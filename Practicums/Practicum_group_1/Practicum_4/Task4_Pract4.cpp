#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Даден е вектор от цели положителни числа.Напишете програма,
//която разделя масива на две части, като първата част съдържа всички числа с четен брой цифри, 
//а втората част - всички с нечетен брой.


unsigned countDigits(int num) {
	unsigned count = 0;
	while (num != 0) {
		count++;
		num /= 10;
	}
	return count;
}

bool isEven(int num) {
	return num % 2 == 0;
}

bool isEvenDigitsCount(int num) {
	return isEven(countDigits(num));
}


int main() {

	vector<int> vec = { 12,345,89,3,445,7899,3 };
	auto it = partition(vec.begin(), vec.end(), isEvenDigitsCount);

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}