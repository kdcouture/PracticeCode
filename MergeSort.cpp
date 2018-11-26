#include <iostream>

using namespace std;

// Prototype
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

void mergeSort(int arr[], int l, int r) {

	// Base Case size = 1 : check for array of size 1
	if (l >= 0 && l < r) {
		// Find the middle element
		int mid = l + (r - l) / 2;
	
		// Recursive sort calls
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		// Merge arrays
		merge(arr, l, mid, r);
	}
	else {
		return;
	}
}

void merge(int arr[], int L, int m, int r) {
	// Prepare variables
	int lSize = m - L + 1;
	int rSize = r - m;
	int lIdx = 0;
	int rIdx = 0;
	int arrIdx = L; // Current section start of original array
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
}

void printArray(int arr[], int size)
{
	cout << "Current Array : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}
