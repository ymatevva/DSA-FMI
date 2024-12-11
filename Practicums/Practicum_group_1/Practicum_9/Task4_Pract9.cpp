// LeetCode Task 1234: Maximum Frequency Elements
// Link: https://leetcode.com/problems/task-id-placeholder/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> myMap;
    for (int num : nums) {
        myMap[num]++;
    }

    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> myPQ(comp);

    for (auto pair : myMap) {
        myPQ.push({pair.first, pair.second});
    }

    size_t count = 0;
    while (true) {
        int topElOcc = myPQ.top().second;
        myPQ.pop();
        count += topElOcc;
        if (myPQ.empty() || myPQ.top().second != topElOcc) {
            break;
        }
    }

    return count;
}
