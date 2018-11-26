/*
MergeSort.cpp

@desc This file contains the C++ code for
 the merge sort function on a given int array.
*/

// Includes

#include <iostream>

using namespace std;

// Prototypes

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int size);


// Main
int main(){
	int ourArray[] = { 7,3,65,1,9,12,54,24};
	int arrSize = sizeof(ourArray) / sizeof(ourArray[0]);
	printArray(ourArray, arrSize);
	cout << "Size " << arrSize << endl;
	mergeSort(ourArray, 0, arrSize-1);
	cout << "After sort " << endl;
	printArray(ourArray, arrSize);
	system("pause");
	return 0;
}

/*
@func mergeSort
@param int[] arr, int L, int r
@ret VOID
@desc This function recursivly calls iteself
 to sort an array. The function breaks the array
 int to two subarrays until the base case of a single
 element.
*/
void mergeSort(int arr[], int L, int r) {

	// Base Case size = 1 : check for array of size 1
	if (L >= 0 && L < r) {
		// Find the middle element
		int mid = L + (r - L) / 2;
	
		// Recursive sort calls
		mergeSort(arr, L, mid);
		mergeSort(arr, mid+1, r);
		// Merge arrays
		merge(arr, L, mid, r);
	}
	else {
		return;
	}
}

/*
@func merge
@param int[] arr, int L, int m, int r
@ret VOID
@desc A function that will sort the two subarrays
 while updating the original array.
*/
void merge(int arr[], int L, int m, int r) {
	// Prepare variables
	int lSize = m - L + 1;
	int rSize = r - m;
	int lIdx = 0;
	int rIdx = 0;
	int arrIdx = L; // Current segment start of original array
	// Create temp storage
	int* lArr = new int[lSize];
	int* rArr = new int[rSize];
	// Copy data to temp arrays
	for (int i = 0; i < lSize; i++) {
		lArr[i] = arr[L + i];
	}
	for (int j = 0; j < rSize; j++) {
		rArr[j] = arr[m + 1 + j];
	}
	// Sort temp arrays into original array
	while (lIdx < lSize && rIdx < rSize) {
		if (lArr[lIdx] <= rArr[rIdx]){
			arr[arrIdx] = lArr[lIdx];
			lIdx++;
		}
		else {
			arr[arrIdx] = rArr[rIdx];
			rIdx++;
		}
		arrIdx++;
	}
	// Place any remaining elements
	while (lIdx < lSize) {
		arr[arrIdx] = lArr[lIdx];
		lIdx++;
		arrIdx++;
	}
	while (rIdx < rSize) {
		arr[arrIdx] = rArr[rIdx];
		rIdx++;
		arrIdx++;
	}
	// Free Memory
	delete[] lArr;
	delete[] rArr;
	lArr = NULL;
	rArr = NULL;
}

/*
@func printArray
@param int[] arr, int size
@ret VOID
@desc A function to print the given array.
*/
void printArray(int arr[], int size)
{
	cout << "Current Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}
