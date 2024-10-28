#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

bool isEven(int num) {
	return num % 2 == 0;
}

unsigned countEven(vector<int>& vec) {
	unsigned count = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (isEven(vec[i])) {
			count++;
		}
	}
	return count;
}

void sortEvenOdd(vector<int>& vec) {

	int left = 0;
	int right = countEven(vec);

	vector<int> res(vec.size());
	
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] % 2 == 0) {
			res[left++] = vec[i];
		}
		else {
			res[right++] = vec[i];
		}
	}
	vec = res;
}
int main() {

	vector<int> v1 = { 1, 1, 2, 3, 4, 5, 6 };
	vector<int> v2 = { 1, 1, 1, 2, 2, 2, 3, 9 };

	vector<int> res(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());

	sortEvenOdd(res);
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " ";
	}
	return 0;
}