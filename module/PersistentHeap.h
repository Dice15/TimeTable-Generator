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
		int curr_vertex, next_vertex;

		Node(ValueType _value, int _curr_vertex, int _next_vertex) : Node((Node*)nullptr, (Node*)nullptr, _value, _curr_vertex, _next_vertex) {}
		Node(Node* _left_son, Node* _right_son, ValueType _value, int _curr_vertex, int _next_vertex) : value(_value), curr_vertex(_curr_vertex), next_vertex(_next_vertex) { son[0] = _left_son; son[1] = _right_son; }
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
	static Node* NodeCopy(Node* node) {
		if (node == (Node*)nullptr) return (Node*)nullptr;
		return new Node(node->son[0], node->son[1], node->value, node->curr_vertex, node->next_vertex);
	}

	static Node* NodeMerge(Node* x, Node* y, function<int(int, int)>& RandomInt) {
		if (x == (Node*)nullptr) return y;
		if (y == (Node*)nullptr) return x;
		if (x->value > y->value ? true : x->value == y->value ? x->next_vertex > y->next_vertex : false) swap(x, y);
		int idx = RandomInt(0, 1);
		if (x->son[idx] != (Node*)nullptr) x->son[idx] = NodeCopy(x->son[idx]);
		x->son[idx] = NodeMerge(x->son[idx], y, RandomInt);
		return x;
	}
};