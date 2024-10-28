#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


bool lexOrder(const string& str1, const string& str2) {
	return str1[0] < str2[0];
}

void reorderLex(vector<string>& vec) {

	vector<vector<string>> letters(26);
	for (size_t i = 0; i < vec.size(); i++)
	{
		letters[vec[i][0] - 'a'].push_back(vec[i]);
	}

	vector<string>temp(vec.size());

	unsigned pos = 0;
	for (size_t i = 0; i < 26; i++)
	{
		if (letters.size()) {

			for (size_t j= 0; j < letters[i].size(); j++)
			{
				temp[pos++] = letters[i][j];
			}
		}
	}

	vec = temp;
}


int main() {

	vector<string> vec = { "banana", "apple", "alpaca", "cat", "biscuit", "elephant", "string", "house", "progress", "trousers", "mouse" };
	reorderLex(vec);
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
}