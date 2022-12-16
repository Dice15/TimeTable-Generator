#pragma once

#include <functional>
#include <algorithm>
#include <vector>
using namespace std;



class PersistentHeap
{
public:
	using ValueType = long long;

	struct Node {
		Node* son[2];
		ValueType value;
		int currVertex, nextVertex;

		Node(ValueType _value, int _currVertex, int _nextVertex) : Node((Node*)nullptr, (Node*)nullptr, _value, _currVertex, _nextVertex) {}
		Node(Node* _leftSon, Node* _rightSon, ValueType _value, int _currVertex, int _nextVertex) : value(_value), currVertex(_currVertex), nextVertex(_nextVertex) { son[0] = _leftSon; son[1] = _rightSon; }
	};



private:
	size_t mHeapTableSize;
	vector<Node*> mHeapTable;



public:
	PersistentHeap() :PersistentHeap(0) {}
	PersistentHeap(size_t heapSize) :mHeapTableSize(heapSize), mHeapTable(vector<Node*>(heapSize, (Node*)nullptr)) {}

	Node*& operator[](int index) { return mHeapTable[index]; }

	void Assign(size_t heapSize) { mHeapTableSize = heapSize; mHeapTable.assign(heapSize, (Node*)nullptr); }



public:
	static Node* NodeCopy(Node* node) {   // �Ķ���ͷ� ���� node�� �����ϰ� ��ȯ
		if (node == (Node*)nullptr) return (Node*)nullptr;
		return new Node(node->son[0], node->son[1], node->value, node->currVertex, node->nextVertex);
	}

	static Node* NodeMerge(Node* x, Node* y, function<int(int, int)>& RandomInt) {   // �־��� �� ���� node�� ��ġ�� �ֻ��� ��带(root)�� ��ȯ�Ѵ�
		if (x == (Node*)nullptr) return y;
		if (y == (Node*)nullptr) return x;
		if (x->value > y->value ? true : x->value == y->value ? x->nextVertex > y->nextVertex : false) swap(x, y);
		int idx = RandomInt(0, 1);
		if (x->son[idx] != (Node*)nullptr) x->son[idx] = NodeCopy(x->son[idx]);
		x->son[idx] = NodeMerge(x->son[idx], y, RandomInt);
		return x;
	}
};