#include <iostream>
#include <vector>
#include <queue>
// LeetCode Task: 912
// Link: https://leetcode.com/problems/sort-an-array/

using namespace std;

vector<int> sortArray(vector<int>& nums) {
    auto comp = [](int a, int b) {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(comp)> myPQ(nums.begin(), nums.end(), comp);

    vector<int> res;
    while (!myPQ.empty()) {
        res.push_back(myPQ.top());
        myPQ.pop();
    }
    return res;
}

int main() {
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sorted = sortArray(nums);
    for (int num : sorted) {
        cout << num << " ";
    }
    return 0;
}
