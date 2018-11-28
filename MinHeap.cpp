/*
Min heap class
This file contains the min heap class and its
related functions. Note: the heap size determins
the vaild heap bound.
*/

#include <iostream>

using namespace std;

// Uitility function

// Heap sort
int* heapSort(int* arr, int size);

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
		heapEls[i] = 999;
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
		heapEls[0] = heapEls[heapSize - 1];
		heapSize--;
		MinHeapify(0);
		return minEle;
	}
	return -1;
}

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

void MinHeap::deleteEle(int data)
{
	for (int i = 0; i < heapSize; i++) {
		if (heapEls[i] == data) {
			heapEls[i] = heapEls[heapSize - 1];
			heapSize--;
			MinHeapify(i);
			break;
		}
	}
}


int* heapSort(int* arr, int size) {
	MinHeap h(arr[0]);
	int* sortedArr = new int[size];
	for (int i = 0; i < size; i++) {
		h.insertEle(arr[i]);
	}
	for (int j = 0; j < size; j++) {
		sortedArr[j] = h.removeMin();
	}
	return sortedArr;
}

int main()
{
	MinHeap h(10);
	h.insertEle(7);
	h.insertEle(6);
	h.deleteEle(1);
	h.insertEle(16);
	h.insertEle(8);
	h.printHeapArray();
	cout << h.getMin() << endl;
	cout << h.removeMin() << endl;
	h.printHeapArray();
	cout << h.removeMin() << endl;
	h.printHeapArray();
	cout << h.getMin() << endl;
	int* arr = new int[7];
	int size = 7;
	for (int i = 0; i < size; i++) {
		arr[i] = 52 - i;
	}
	int* sorted = heapSort(arr, size);
	for (int j = 0; j < size; j++) {
		cout << sorted[j] << " ";
	} cout << endl;

	system("pause");
	return 0;
}