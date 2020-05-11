#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Node
{
public:
	T value;
	int key;

	Node();
};
template <class T>
class Priority_queue
{
private:
	vector<Node<T>>arr;
	int count;
	//int size;
public:
	Priority_queue();
	void Push(T value,int key);
	void Pop();
	int parent(int);
	int left(int);
	int right(int);
	void heapify_up(int);
	void heapify_down(int);
	void Expand();
	int Size();
	T Top();
	bool Empty();
	bool isFull();
	bool hasRight(int);
	bool hasLeft(int);
	~Priority_queue();
};