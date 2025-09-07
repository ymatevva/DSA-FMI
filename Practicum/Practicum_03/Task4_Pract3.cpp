#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool hasEvenCounOfDigits(unsigned num) {

	unsigned count = 0;
	while (num != 0) {
		count++;
		num /= 10;
	}
	return count % 2 == 0;
}

int main() {

	vector<int> vec = { 10, 2, 16, 12, 4, 100,4567, 102020 };
	partition(vec.begin(), vec.end(), hasEvenCounOfDigits);

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}