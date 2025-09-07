#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
// LeetCode Task: 692
//https://leetcode.com/problems/top-k-frequent-words/?envType=problem-list-v2&envId=a4i937t6

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> myMap;

    for (string word : words) {
        myMap[word]++;
    }

    auto compare = [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> myPQ(compare);

    for (auto pair : myMap) {
        myPQ.push({pair.first, pair.second});
    }

    vector<string> res;

    while (k--) {
        res.push_back(myPQ.top().first);
        myPQ.pop();
    }

    return res;
}

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> result = topKFrequent(words, k);
    for (string word : result) {
        cout << word << " ";
    }
    return 0;
}
