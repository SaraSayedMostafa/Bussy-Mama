#include "Priority_queue.h"
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template <class T>
Node<T>::Node()
{
	key = 0;
}
template <class T>
Priority_queue<T>::Priority_queue()
{
	count = 0;
}
template <class T>
int Priority_queue<T>::parent(int i)
{
	return ((i - 1) / 2);
}
template <class T>
int Priority_queue<T>::right(int i)
{
	return (i * 2 + 2);
}
template <class T>
int Priority_queue<T>::left(int i)
{
	return (i * 2 + 1);
}
template <class T>
bool Priority_queue<T>::hasLeft(int i)
{
	return (left(i) < count);
}
template <class T>
bool Priority_queue<T>::hasRight(int i)
{
	return (right(i) < count);
}
template <class T>
void Priority_queue<T>::heapify_up(int i)
{
	/*if (i&&arr[parent(i)].key < arr[i].key){
	//	swap(arr[parent(i)].value, arr[parent(i)].value);
	//swap(arr[parent(i)].key, arr[parent(i)].key);
	swap(arr[parent(i)], arr[i]);
	heapify_up(parent(i));
	}
	*/
	while (i && arr[parent(i)].key < arr[i].key)   //if i=0 then it has no parent so the loop stops (instead of using hasParent() fn.
	{

		swap(arr[parent(i)], arr[i]);

		i = parent(i);
	}
}

template <class T>
void Priority_queue<T>::heapify_down(int i)
{
	/*int Left = left(i);
	int Right = right(i);
	int largest = i;
	if (hasLeft(i) && (arr[i].key < arr[Left].key))
	largest = Left;
	//swap(arr[i], arr[Left]);

	if (hasRight(i) && arr[i].key < arr[Right].key)
	largest = Right;
	//swap(arr[i], arr[Right]);
	if (largest != i){
	swap(arr[largest], arr[i]);
	heapify_down(largest);
	}*/
	while (hasLeft(i))
	{
		int largest = left(i);
		if (hasRight(i) && arr[right(i)].key > arr[left(i)].key)
			largest = right(i);
		if (arr[i].key > arr[largest].key)
			break;
		else
			swap(arr[largest], arr[i]);
		i = largest;
	}
}

template <class T>
void Priority_queue<T>::Push(T val, int k)
{
	Node<T>temp;
	temp.value = val;
	temp.key = k;
	arr.push_back(temp);
	count++;
	heapify_up(count - 1);

}
template <class T>
void Priority_queue<T>::Pop()
{
	assert(!Empty());
	arr[0] = arr[count - 1];
	//arr[0]=arr.back();
	arr.pop_back();
	count--;
	heapify_down(0);
}
template <class T>
int Priority_queue<T>::Size()
{
	return count;
}
template <class T>
bool Priority_queue<T>::Empty()
{
	return (count == 0);
}
template <class T>
T Priority_queue<T>::Top()
{
	assert(!Empty());
	return arr[0].value;
}
/*template <class T>
void Priority_queue<T>::Expand()
{

Node<T>* temp = new Node<T>[size*2];
for (int i = 0; i < size; i++)
{
//temp[i].value = arr[i].value;
//temp[i].key = arr[i].key;
temp[i] = arr[i];
}
size = size * 2;
delete[]arr;
arr = temp;
}
*/
/*template <class T>
bool Priority_queue<T>::isFull()
{
return (count == size);
}*/

template <class T>
Priority_queue<T>::~Priority_queue()
{
}