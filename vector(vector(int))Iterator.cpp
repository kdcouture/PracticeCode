#include <iostream>
#include <vector>


using namespace std;

// Prototypes
bool hasNext(vector<int>* vptr, int* iptr, unsigned int* vcount, unsigned int* icount, unsigned int maxVectors);
void Next(vector<int>* & vptr, int** iptr, unsigned int** vcount, unsigned int** icount, unsigned int maxVectors, vector<vector<int>> twoD);

int main() {

	// Input
	vector<vector<int>> twoD = { {1}, {2,3,4} };
	// Vars
	vector<int>* vptr = &twoD.at(0);
	int* iptr = &vptr->at(0);
	unsigned int* icount = new unsigned int(0);
	unsigned int* vcount = new unsigned int(0);
	int maxVectors = twoD.size();
	cout << "max Vectors = " << maxVectors << endl;
	cout << "vptr[0]: " << vptr->at(0) << " | iptr: " << *iptr << endl;
	while (hasNext(vptr, iptr, vcount, icount, maxVectors)) {
		Next(vptr, &iptr, &vcount, &icount, maxVectors, twoD);
		cout << "vptr[0]: " << vptr->at(0) << " | iptr: " << *iptr << endl;
	}
	Next(vptr, &iptr, &vcount, &icount, maxVectors, twoD);

	system("pause");
	return 0;
}

bool hasNext(vector<int>* vptr, int* iptr, unsigned int* vcount, unsigned int* icount, unsigned int maxVectors) {
	if (*icount == (vptr->size()-1)) {
		if (*vcount < maxVectors - 1) {
			return true;
		}
	}
	else if (*icount < vptr->size()-1) {
		return true;
	}

	return false;
}

void Next(vector<int>* & vptr, int** iptr, unsigned int** vcount, unsigned int** icount, unsigned int maxVectors, vector<vector<int>> twoD) {
	if (**icount == (vptr->size()-1) && **vcount < (maxVectors-1)) {
		(**vcount)++;
		*vptr = twoD.at(**vcount);
		(**icount) = 0;
		*iptr = &vptr->at(**icount);
	}
	else if (**icount < (vptr->size()-1)) {
		(**icount)++;
		*iptr = &vptr->at(**icount);
	}
	else {
		cout << "No next exists!" << endl;
	}
}