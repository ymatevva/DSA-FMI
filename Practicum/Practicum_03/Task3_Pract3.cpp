#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> unionAndSort(vector<vector<int>>& vec) {

	vector<int> res = vec[0];
	for (size_t i = 1; i < vec.size(); i++)
	{
		vector<int> temp(res.size()+vec[i].size());
		merge(res.begin(), res.end(), vec[i].begin(), vec[i].end(), temp.begin());
		res = temp;
	}

	return res;

}
int main() {

	vector<vector<int>> vec = { {9, 10, 12}, {14, 17, 18}, {10, 11, 12, 22, 90}, {13}, {16, 18} };
	vector<int> sorted = unionAndSort(vec);
	for (size_t i = 0; i < sorted.size(); i++)
	{
		std::cout << sorted[i] << " ";
	}

	return 0;
}