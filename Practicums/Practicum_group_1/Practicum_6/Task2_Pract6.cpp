#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

//Leetcode: 1021
//https://leetcode.com/problems/remove-outermost-parentheses/description/?envType=problem-list-v2&envId=awthx4gv

string removeOuterParentheses(string s) {

	string res;

	unsigned count = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') {

			if (count > 0) {
				res += s[i];
			}
			count++;
		}
		else {
			count--;
			if (count > 0) {
				res += s[i];
			}
		}
	}
	return res;
}


int main() {


	std::string myStr = "(()())(())";
	std::string resAfterRemoving = removeOuterParentheses(myStr);
	std::cout << resAfterRemoving;
	return 0;
}