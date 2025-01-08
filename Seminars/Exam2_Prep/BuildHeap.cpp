#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(size_t ind, vector<int>& data,size_t sizeArr) {

	int smallest = ind;

	size_t leftInd = ind * 2 + 1;
	size_t rightInd = ind * 2 + 2;

	
	if (leftInd < sizeArr && data[leftInd] > data[smallest]) {
		smallest = leftInd;
	}
	if (rightInd < sizeArr && data[rightInd] > data[smallest]) {
		smallest = rightInd;
	}
	if (smallest != ind) {
		swap(data[ind], data[smallest]);
		heapify(smallest, data,sizeArr);
	}
}

void buildHeap(vector<int>& data) {

	for (int i = data.size()/2 -1; i >= 0 ; i--)
	{
		heapify(i, data,data.size());
	}
}


void heapSort(vector<int>& data) {
	buildHeap(data);//0(n)->dalamber

	int minEl = data.size() - 1;

	for (size_t i = 0; i < data.size()-1; i++)//n times we call heapify which is log n in wc so 0(n*logn)
	{
		swap(data[0], data[minEl--]);
		heapify(0, data, minEl);
	}
}

//total 0(n) + 0(n*logn) -> 0(n*logn)
int main() {


	vector<int> vec = { 1,9,3,4,6,12};
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