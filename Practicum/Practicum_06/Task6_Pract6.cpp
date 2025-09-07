#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;


//Leetcode: 1614
//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=problem-list-v2&envId=att3tyhi


int maxDepth(string s) {


    std::stack<int> mySt;
    int maxCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            mySt.push(s[i]);
        }
        else if (s[i] == ')') {
            if (mySt.size() > maxCount) {
                maxCount = mySt.size();
            }
            mySt.pop();

        }
    }
    return maxCount;
}
int main() {


    string str = "(1+(2*3)+((8)/4))+1";
    std::cout << maxDepth(str);
	return 0;
}