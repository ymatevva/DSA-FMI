#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

//In place verse:
// void reorderWordsLex(vector<string>& vec) {

// 	unsigned pos = 0;

// 	for (char  ch = 'a'; ch <= 'z'; ch++)
// 	{
// 		for (size_t i = 0; i < vec.size(); i++)
// 		{
// 			if (vec[i][0] == ch || vec[i][0]  - 'A' + 'a' == ch) {
// 				std::swap(vec[i], vec[pos]);
// 				pos++;
// 			}
// 		}
// 	}
// }

bool isUpper(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

char toLower(char ch) {
	return ch - 'A' + 'a';
}

void reorderWordsLex(vector<string>& vec) {

	vector<vector<string>> letters(26);

	for (size_t i = 0; i < vec.size(); i++)
	{
		char lowerLet = isUpper(vec[i][0]) ? toLower(vec[i][0]) : vec[i][0];
		letters[lowerLet - 'a'].push_back(vec[i]);
	}

	unsigned pos = 0;
	for (size_t i = 0; i < 26; i++)
	{  
		if (letters[i].size()) {
			for (size_t j = 0; j < letters[i].size(); j++)
			{
				vec[pos++]=letters[i][j];
			}
		}
	}
}

int main() {

	vector<string> vec = { "banana", "apple", "Alpaca", "Cat", "biscuit", "elephant", "string", "house", "progress", "Trousers", "mouse"};
	reorderWordsLex(vec);
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}
