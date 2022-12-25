
#pragma once
#include "./../../core/C++Header_STL.h"
#include "./PersistentHeap.h"



class WeightedGraph
{
public:
	using WeightType = long long;
	using Bits = long long;
	using Path = Bits;
	using SuffixPath = pair<Bits, Bits>;
	using PrefixPath = pair<Bits, Bits>;
	using KspPqValue = tuple<WeightType, PersistentHeap::Node*, PrefixPath, int>;

	struct Edge {
		int nextVertex, id;
		WeightType weight;
		Edge(int _next, WeightType _weight, int _id) :nextVertex(_next), weight(_weight), id(_id) {}
	};



private:
	WeightType mMaxValue, mBigValue, mEmptyValue;

	int mSource, mSink, mGraphSize, mEdgeCount;      // 그래프의 시작점, 그래프의 끝점, 그래프의 크기 (=정점의 개수), 간선의 개수
	vector<vector<Edge>> mGraph;                     // 그래프
	vector<vector<Edge>> mReverseGraph;              // 역방향 그래프

	PersistentHeap mPersistentHeap;                  // 퍼시스턴트 힙

	vector<int> mNextVertex;                         // 각 정점에서 이동해야할 다음 정점
	vector<WeightType> mDistance;                    // 각 정점에서 Sink까지의 최단경로 가중치
	vector<SuffixPath> mSuffixPath;                  // 각 정점에서 Sink까지의 경로 상태(포함된 정점, 이 경로와 충돌되는 정점)

	vector<Path> mPath;                                                           // ksp로 찾은 경로를 반환
	priority_queue<KspPqValue, vector<KspPqValue>, greater<KspPqValue>> mKspPq;   // ksp를 여러번 수행하므로 pq가 유지되어야 한다



public:   // 그래프를 구성하는 멤버 함수
	void Assign(size_t _size, WeightType _inf_value, WeightType _big_value, WeightType _empty_value) {
		mGraphSize = _size;
		mMaxValue = _inf_value;
		mBigValue = _big_value;
		mEmptyValue = _empty_value;
		mEdgeCount = 0;
		mGraph.assign(_size, vector<Edge>());
		mReverseGraph.assign(_size, vector<Edge>());
	}

	void Resize(size_t _size) {
		mGraphSize = _size;
		mGraph.resize(_size, vector<Edge>());
		mReverseGraph.resize(_size, vector<Edge>());
	}

	void Add_Directed_Edge(int _from, int _to, WeightType _weight) {
		mGraph[_from].push_back(Edge(_to, _weight, mEdgeCount));
		mReverseGraph[_to].push_back(Edge(_from, _weight, mEdgeCount));
		mEdgeCount++;
	}



private:   // 역방향 그래프에 대해 최단경로를 구함
	void Dijkstra_Of_ReverseGraph(vector<int>& usedEdge, vector<int>& visitedVertex)
	{
		priority_queue<pair<WeightType, int>, vector<pair<WeightType, int>>, greater<pair<WeightType, int>>> pq;
		mNextVertex.assign(mGraphSize, -1);         // Rev Dijkstra에서의 정점간 이동
		usedEdge.assign(mGraphSize, -1);            // Rev Dijkstra에서 사용했던 간선
		visitedVertex.clear();                      // Rev Dijkstra에서 방문했던 정점
		mDistance.assign(mGraphSize, mMaxValue);    // Sink에서 각 정점까지의 최단거리

		auto Enque = [&](int currVertex, int nextVertex, WeightType pathWeight, int edgeID) {
			if (mDistance[nextVertex] > pathWeight) {
				mDistance[nextVertex] = pathWeight;
				mNextVertex[nextVertex] = currVertex;
				usedEdge[nextVertex] = edgeID;
				pq.emplace(pathWeight, nextVertex);
			}
		};

		Enque(-1, mSink, mEmptyValue, -1);
		while (!pq.empty()) {
			auto [pathWeight, currVertex] = pq.top(); pq.pop();

			if (mDistance[currVertex] != pathWeight) continue;
			visitedVertex.push_back(currVertex);

			for (auto& edge : mReverseGraph[currVertex]) Enque(currVertex, edge.nextVertex, edge.weight + pathWeight, edge.id);
		}
	}



private:   // 역방향 최단경로를 활용하여 Persistent-Heap 구성
	void Construct_PersistentHeap(vector<int>& usedEdge, vector<int>& visitedVertex)
	{
		mt19937 randomGenerator(0x69420);
		function<int(int, int)> RandomInt = [&](int lb, int ub) { return uniform_int_distribution<int>(lb, ub)(randomGenerator); };

		mPersistentHeap.Assign(mGraphSize);

		for (auto& vertex : visitedVertex) {
			if (mNextVertex[vertex] != -1) 
				mPersistentHeap[vertex] = PersistentHeap::NodeCopy(mPersistentHeap[mNextVertex[vertex]]);

			for (auto& edge : mGraph[vertex]) {
				if (edge.id == usedEdge[vertex]) continue;   // 최단경로에서 사용된 간선이라면 스킵

				WeightType sidetrack = mDistance[edge.nextVertex] + edge.weight - mDistance[vertex];   // sidetrack 가중치 = sidetrack(u, v, w) =  d[v] + w - d[u];

				if (sidetrack < mBigValue)   // 현재 정점의 heap과 다음 정점의 힙을 합친다
					mPersistentHeap[vertex] = PersistentHeap::NodeMerge(mPersistentHeap[vertex], new PersistentHeap::Node(sidetrack, vertex, edge.nextVertex), RandomInt);
			}
		}
	}



private:   // 역방향 최단경로를 활용하여 Suffix-Path를 미리 구해둠 (KSP에서 경로를 복원할 때 중복 연산을 방지하기 위한 작업)
	SuffixPath Dfs_for_SuffixPath(int currVertex, vector<Bits>& vertexConflict, function<int(int)>& GetVertexNum)
	{
		if (mSuffixPath[currVertex].first > 0) return mSuffixPath[currVertex];
		auto _select = Dfs_for_SuffixPath(mNextVertex[currVertex], vertexConflict, GetVertexNum);

		_select.first |= (Bits)1 << (Bits)GetVertexNum(currVertex);
		_select.second |= vertexConflict[GetVertexNum(currVertex)];

		return mSuffixPath[currVertex] = _select;
	}

	void Construct_SuffixPath(vector<Bits>& vertexConflict, function<int(int)>& GetVertexNum)
	{
		mSuffixPath.assign(mGraphSize, SuffixPath(0, 0));
		mSuffixPath[mSink] = SuffixPath((Bits)1 << (Bits)GetVertexNum(mSink), (Bits)0);
		for (int i = 0; i < mGraphSize; i++)
			if (mNextVertex[i] != -1) Dfs_for_SuffixPath(i, vertexConflict, GetVertexNum);
	}



public:   // Ksp를 위한 전처리 작업을 한 뒤, Ksp를 수행하고 그 결과를 반환한다
	vector<Path> Construct_Ksp(int source, int sink, int kValue, vector<Bits>& vertexConflict, function<int(int)>& GetVertexNum)
	{
		mSource = source;
		mSink = sink;
		mPath.reserve(kValue);

		vector<int> usedEdge, visitedVertex;
		Dijkstra_Of_ReverseGraph(usedEdge, visitedVertex);
		Construct_PersistentHeap(usedEdge, visitedVertex);
		Construct_SuffixPath(vertexConflict, GetVertexNum);

		if (mDistance[mSource] > mBigValue) return vector<Path>();

		// mKspPq의 초기값 설정
		auto prefix = PrefixPath((Bits)1, (Bits)0);
		auto suffix = mSuffixPath[mNextVertex[mSource]];

		if (mPersistentHeap[mSource] != nullptr)
			mKspPq.emplace(mDistance[mSource] + mPersistentHeap[mSource]->value, mPersistentHeap[mSource], prefix, mSource);

		if (!((prefix.first | suffix.first) & (prefix.second | suffix.second))) {   // 첫번 째 경로에서 충돌이 없다면
			Additional_Ksp(kValue - 1, vertexConflict, GetVertexNum);   // 추가로 kValue-1개만 찾으면 된다
			mPath.insert(mPath.begin(), prefix.first | suffix.first);   // mPath(결과)에 포함
		}
		else Additional_Ksp(kValue, vertexConflict, GetVertexNum);

		return mPath;
	}

	

public:   // 추가로 Ksp를 진행하고 그 결과를 반환한다
	vector<Path> Additional_Ksp(int kValue, vector<Bits>& vertexConflict, function<int(int)>& GetVertexNum)
	{
		auto AddPath = [&](PrefixPath& prefix, SuffixPath& suffix) {
			if ((prefix.first | suffix.first) & (prefix.second | suffix.second)) return;
			mPath.push_back(prefix.first | suffix.first);
		};

		auto InsertVertexToPrefix = [&](PrefixPath& prefix, int &preifxBack, int newVertex) {
			prefix.first |= ((Bits)1 << (Bits)GetVertexNum(newVertex));
			prefix.second |= vertexConflict[GetVertexNum(newVertex)];
			preifxBack = newVertex;
		};

		mPath.clear();

		while (!mKspPq.empty() && (int)mPath.size() < kValue) {
			auto [weight, node, prefix, prefixBack] = mKspPq.top();
			auto newPrefix = prefix;
			auto newPxBack = prefixBack;
			mKspPq.pop();

			if (newPxBack == node->currVertex) InsertVertexToPrefix(newPrefix, newPxBack, node->nextVertex);
			else {
				for (int vertex = mNextVertex[newPxBack]; vertex != node->currVertex; vertex = mNextVertex[vertex]) InsertVertexToPrefix(newPrefix, newPxBack, vertex);
				InsertVertexToPrefix(newPrefix, newPxBack, node->currVertex);
				InsertVertexToPrefix(newPrefix, newPxBack, node->nextVertex);
			}

			AddPath(newPrefix, mSuffixPath[mNextVertex[newPxBack]]);

			for (int i = 0; i < 2; i++) {
				if (node->son[i] != (PersistentHeap::Node*)nullptr)   // 현재 node의 Edge는 포함하지 않는다
					mKspPq.emplace(weight - node->value + node->son[i]->value, node->son[i], prefix, prefixBack);
			}

			if (!(newPrefix.first & newPrefix.second) && mPersistentHeap[newPxBack] != (PersistentHeap::Node*)nullptr)   // 현재 node의 Edge 보존
				mKspPq.emplace(weight + mPersistentHeap[newPxBack]->value, mPersistentHeap[newPxBack], newPrefix, newPxBack);
		}

		return mPath;
	}
};