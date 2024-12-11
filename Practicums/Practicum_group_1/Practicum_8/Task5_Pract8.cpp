#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// LeetCode Task: 347
// Link: https://leetcode.com/problems/top-k-frequent-elements/

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> myMap;
        for (int num : nums) {
            myMap[num]++;
        }

        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> myPQ(compare);

        for (auto iter : myMap) {
            myPQ.push({iter.first, iter.second});
        }

        int index = 0;
        vector<int> res(k);

        while (k > 0) {
            res[index++] = myPQ.top().first;
            myPQ.pop();
            k--;
        }

        return res;
    }


int main() {
 
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

