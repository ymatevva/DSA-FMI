#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

//Leetcode: 1598
//https://leetcode.com/problems/crawler-log-folder/?envType=problem-list-v2&envId=awth2fv7

int minOperations(vector<string>& logs) {

    stack<string>mySt;

    for (int i = 0; i < logs.size(); i++) {
        if (logs[i] == "../") {
            if (!mySt.empty()) {
                mySt.pop();
            }
        }
        else if (logs[i] == "./") {
            continue;
        }
        else {
            mySt.push(logs[i]);
        }
    }
    return mySt.size();
}
int main() {


    vector< string> str = { "d1/", "d2/", "./", "d3/", "../", "d31/" };
    std::cout << minOperations(str);
	return 0;
}