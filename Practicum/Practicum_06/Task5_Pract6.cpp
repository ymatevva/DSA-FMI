#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;


//Leetcode: 844
//https://leetcode.com/problems/backspace-string-compare/


bool areStringTheSame(const string& str1, const string& str2) {

	std::stack<char> st1;
	std::stack<char> st2;

	for (size_t i = 0; i < str1.size(); i++)
	{
		if (str1[i] != '#') {
			st1.push(str1[i]);
		}
		else if (!st1.empty()) {
			st1.pop();
		}
	}
	for (size_t i = 0; i < str2.size(); i++)
	{
		if (str2[i] != '#') {
			st2.push(str2[i]);
		}
		else if (!st2.empty()) {
			st2.pop();
		}
	}
	return st1 == st2;
}
int main() {


	string str1 = "ab#c";
	string str2 = "ad#c";
	std::cout << std::boolalpha << areStringTheSame(str1, str2);
	return 0;
}
