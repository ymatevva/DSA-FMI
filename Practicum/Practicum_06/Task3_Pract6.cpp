#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>w

using namespace std;


//Leetcode: 682
// https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=awthx4gv

int calPoints(vector<string>& operations) {

	std::stack<int> record;
	size_t sum = 0;
	
	for (size_t i = 0; i < operations.size(); i++)
	{
		if (operations[i] == "+"){
			int lastNum = record.top();
			record.pop();
			int prevLastNum = record.top();
			int numToAdd = lastNum + prevLastNum;
			record.push(lastNum);
			record.push(numToAdd);
		}
		else if (operations[i] == "D") {
			int lastScore = record.top();
			record.push(lastScore * 2);
		}
		else if (operations[i] == "C") {
			record.pop();
		}
		else {
			record.push(stoi(operations[i]));
		}
	}

	size_t end = record.size();
	for (size_t i = 0; i < end; i++)
	{
		sum += record.top();
		record.pop();
	}
	return sum;
}
int main() {

	vector<string> myStr = { "5", "-2", "4", "C", "D", "9", "+", "+" };// 5 -2 -4 9  5 14
	std::cout << calPoints(myStr);
	return 0;
}