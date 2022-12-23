
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

	int mSource, mSink, mGraphSize, mEdgeCount;      // �׷����� ������, �׷����� ����, �׷����� ũ�� (=������ ����), ������ ����
	vector<vector<Edge>> mGraph;                     // �׷���
	vector<vector<Edge>> mReverseGraph;              // ������ �׷���

	PersistentHeap mPersistentHeap;                  // �۽ý���Ʈ ��

	vector<int> mNextVertex;                         // �� �������� �̵��ؾ��� ���� ����
	vector<WeightType> mDistance;                    // �� �������� Sink������ �ִܰ�� ����ġ
	vector<SuffixPath> mSuffixPath;                  // �� �������� Sink������ ��� ����(���Ե� ����, �� ��ο� �浹�Ǵ� ����)

	vector<Path> mPath;                                                           // ksp�� ã�� ��θ� ��ȯ
	priority_queue<KspPqValue, vector<KspPqValue>, greater<KspPqValue>> mKspPq;   // ksp�� ������ �����ϹǷ� pq�� �����Ǿ�� �Ѵ�



public:   // �׷����� �����ϴ� ��� �Լ�
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



private:   // ������ �׷����� ���� �ִܰ�θ� ����
	void Dijkstra_Of_ReverseGraph(vector<int>& usedEdge, vector<int>& visitedVertex)
	{
		priority_queue<pair<WeightType, int>, vector<pair<WeightType, int>>, greater<pair<WeightType, int>>> pq;
		mNextVertex.assign(mGraphSize, -1);         // Rev Dijkstra������ ������ �̵�
		usedEdge.assign(mGraphSize, -1);            // Rev Dijkstra���� ����ߴ� ����
		visitedVertex.clear();                      // Rev Dijkstra���� �湮�ߴ� ����
		mDistance.assign(mGraphSize, mMaxValue);    // Sink���� �� ���������� �ִܰŸ�

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



private:   // ������ �ִܰ�θ� Ȱ���Ͽ� Persistent-Heap ����
	void Construct_PersistentHeap(vector<int>& usedEdge, vector<int>& visitedVertex)
	{
		mt19937 randomGenerator(0x69420);
		function<int(int, int)> RandomInt = [&](int lb, int ub) { return uniform_int_distribution<int>(lb, ub)(randomGenerator); };

		mPersistentHeap.Assign(mGraphSize);

		for (auto& vertex : visitedVertex) {
			if (mNextVertex[vertex] != -1) 
				mPersistentHeap[vertex] = PersistentHeap::NodeCopy(mPersistentHeap[mNextVertex[vertex]]);

			for (auto& edge : mGraph[vertex]) {
				if (edge.id == usedEdge[vertex]) continue;   // �ִܰ�ο��� ���� �����̶�� ��ŵ

				WeightType sidetrack = mDistance[edge.nextVertex] + edge.weight - mDistance[vertex];   // sidetrack ����ġ = sidetrack(u, v, w) =  d[v] + w - d[u];

				if (sidetrack < mBigValue)   // ���� ������ heap�� ���� ������ ���� ��ģ��
					mPersistentHeap[vertex] = PersistentHeap::NodeMerge(mPersistentHeap[vertex], new PersistentHeap::Node(sidetrack, vertex, edge.nextVertex), RandomInt);
			}
		}
	}



private:   // ������ �ִܰ�θ� Ȱ���Ͽ� Suffix-Path�� �̸� ���ص� (KSP���� ��θ� ������ �� �ߺ� ������ �����ϱ� ���� �۾�)
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



public:   // Ksp�� ���� ��ó�� �۾��� �� ��, Ksp�� �����ϰ� �� ����� ��ȯ�Ѵ�
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

		// mKspPq�� �ʱⰪ ����
		auto prefix = PrefixPath((Bits)1, (Bits)0);
		auto suffix = mSuffixPath[mNextVertex[mSource]];

		if (mPersistentHeap[mSource] != nullptr)
			mKspPq.emplace(mDistance[mSource] + mPersistentHeap[mSource]->value, mPersistentHeap[mSource], prefix, mSource);

		if (!((prefix.first | suffix.first) & (prefix.second | suffix.second))) {   // ù�� ° ��ο��� �浹�� ���ٸ�
			Additional_Ksp(kValue - 1, vertexConflict, GetVertexNum);   // �߰��� kValue-1���� ã���� �ȴ�
			mPath.insert(mPath.begin(), prefix.first | suffix.first);   // mPath(���)�� ����
		}
		else Additional_Ksp(kValue, vertexConflict, GetVertexNum);

		return mPath;
	}

	

public:   // �߰��� Ksp�� �����ϰ� �� ����� ��ȯ�Ѵ�
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
				if (node->son[i] != (PersistentHeap::Node*)nullptr)   // ���� node�� Edge�� �������� �ʴ´�
					mKspPq.emplace(weight - node->value + node->son[i]->value, node->son[i], prefix, prefixBack);
			}

			if (!(newPrefix.first & newPrefix.second) && mPersistentHeap[newPxBack] != (PersistentHeap::Node*)nullptr)   // ���� node�� Edge ����
				mKspPq.emplace(weight + mPersistentHeap[newPxBack]->value, mPersistentHeap[newPxBack], newPrefix, newPxBack);
		}

		return mPath;
	}
};