#include<iostream>
#include<vector>

using namespace std;


void heapify(vector<int>&vec, int ind, int vecSize) {

	int currInd = ind;

	int leftInd = ind * 3 + 1;
	int midInd = ind * 3 + 2;
	int rightInd = ind * 3 + 3;

	if (vecSize > leftInd && vec[leftInd] > vec[currInd]) {
		currInd = leftInd;
	}
	if (vecSize > midInd && vec[midInd] > vec[currInd]) {
		currInd = midInd;
	}
	if (vecSize > rightInd && vec[rightInd] > vec[currInd]) {
		currInd = rightInd;
	}
	if (currInd != ind) {
		swap(vec[currInd], vec[ind]);
		heapify(vec, currInd,vecSize);
	}
}

void buildHeap(vector<int>& vec) {

	for (int i = vec.size()/3 - 1; i >= 0 ; i--)
	{
		heapify(vec, i,vec.size());
	}
}

void heapSort(vector<int>& vec) {
	buildHeap(vec);

	int minInd = vec.size() - 1;
	for (size_t i = 0; i < vec.size(); i++)
	{
		swap(vec[0], vec[minInd]);
		heapify(vec, 0, minInd--);
	}
}

int main() {


	vector<int> vec = { 1,9,3,4,6,12 };
	buildHeap(vec);
	for (auto it : vec) {
		std::cout << it << " ";
	}
	std::cout << std::endl;
	/*buildHeapNaive(vec);
	for (auto it : vec) {
		std::cout << it << " ";
	}*/
	heapSort(vec);
	for (auto it : vec) {
		std::cout << it << " ";
	}

}