/*
MinHeap.cpp

Min heap class

@desc This file contains the min heap class and its
 related functions. Note: the heap size determins
 the vaild heap bound.
 
Note: currently only works with nums from INT_MIN to 998
 
*/

#include <iostream>

using namespace std;

// Uitility function
// Swaps two integers.
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

class MinHeap {
	// array of elements
	int* heapEls;
	// Maximum size of heap
	int capacity;
	// Current size
	int heapSize;

public:
	// Consturctor
	MinHeap(int cap);

	// Tree utilities
	// Gets parent node ((idx - 1) /2)
	int parent(int idx) {
		return (idx - 1) / 2;
	}
	// Gets left child (idx*2 + 1)
	int left(int idx) {
		return (idx * 2 + 1);
	}
	// Gets right child (idx*2 + 2)
	int right(int idx) {
		return (idx * 2 + 2);
	}
	// Gets the min value
	int getMin() {
		return heapEls[0];
	}
	// Print arry for debug use
	void printHeapArray() {
		for (int i = 0; i < heapSize; i++) {
			cout << heapEls[i] << " ";
		}
		cout << endl;
	}
	// Class prototypes
	void MinHeapify(int idx);
	int removeMin();
	void insertEle(int data);
	void deleteEle(int data);
	
};

// Heap constructor
MinHeap::MinHeap(int cap)
{
	capacity = cap;
	heapEls = new int[capacity];
	heapSize = 0;
	for (int i = 0; i < capacity; i++) {
		heapEls[i] = 999; // inits to 999 for unasigned elements.
	}
}

/*
@func MinHeapify
@param int idx
@ret VOID
@desc This function min heapifies from idx down to 
heap boundry (heapSize).
*/
void MinHeap::MinHeapify(int idx)
{
	int lChild = left(idx);
	int rChild = right(idx);
	int minIdx = idx;
	// Look for smallest while staying inside current heap bounds
	if (lChild < heapSize && heapEls[lChild] < heapEls[idx]) {
		minIdx = lChild;
	}
	if (rChild < heapSize && heapEls[rChild] < heapEls[minIdx]) {
		minIdx = rChild;
	}
	if (minIdx != idx) {
		swap(&heapEls[idx], &heapEls[minIdx]);
		MinHeapify(minIdx);
	}
}

/*
@func removeMin
@param VOID
@ret int min
@desc Returns the minimum element of the minheap
 and removes the node from the heap. Heapifies 
 to ensure valid minheap.
*/
int MinHeap::removeMin()
{
	// Check for empty heap
	if (heapSize <= 0) {
		return -1;
	}
	// If size = 1, return top element
	else if (heapSize == 1) {
		heapSize--;
		return heapEls[0];
	}
	// Remove top element and reheapify
	else {
		int minEle = heapEls[0];
		//heapEls[0] = heapEls[heapSize - 1];
		heapEls[0] = 999;
		heapSize--;
		MinHeapify(0);
		return minEle;
	}
	return -1;
}

/*
@func insertEle
@param int data
@ret VOID
@desc Creates a node with the given data then
 adds it to the bottom of the heap. Modifies heap to ensure it
 it remains valid after the insert.
*/
void MinHeap::insertEle(int data)
{
	// Check if space exists
	if (heapSize == capacity) {
		cout << "Heap is full" << endl;
		return;
	}
	// Increment heap size
	heapSize++;
	// Place new element at bottom of heap
	int i = heapSize - 1;
	heapEls[i] = data;
	// Modify heap until valid min heap
	while (i != 0 && heapEls[parent(i)] > heapEls[i]) {
		swap(&heapEls[i], &heapEls[parent(i)]);
		i = parent(i);
	}
}

/*
@func deleteEle
@param int data
@ret VOID
@desc Searches the heap for a node containing
 the given data. Removes it from the heap 
*/
void MinHeap::deleteEle(int data)
{
	for (int i = 0; i < heapSize; i++) {
		if (heapEls[i] == data) {
			//heapEls[i] = heapEls[heapSize - 1];
			heapEls[0] = 999;
			heapSize--;
			MinHeapify(i);
			break;
		}
	}
}

int main()
{
	MinHeap h(11);
	h.insertEle(3);
	h.insertEle(2);
	h.deleteEle(1);
	h.insertEle(15);
	h.insertEle(5);
	h.insertEle(4);
	h.printHeapArray();
	cout << h.getMin() << endl;
	cout << h.removeMin() << endl;
	h.printHeapArray();
	cout << h.removeMin() << endl;
	h.printHeapArray();
	cout << h.getMin() << endl;
	system("pause");
	return 0;
}