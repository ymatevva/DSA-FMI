#include"TernaryHeap.hpp"


void ternaryHeapSort(vector<int>& vec)
{
	TernaryHeap<int> terH(vec);

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = terH.peek();
		terH.remove();
	}
}

int main() {


	vector<int> vec = { 9,12,3,445,12,-23,6,0,22 };
	ternaryHeapSort(vec);
	for (int num : vec)
	{
		std::cout << num << " ";
	}

}