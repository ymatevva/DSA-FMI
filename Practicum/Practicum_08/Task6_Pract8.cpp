#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
using namespace std;


// LeetCode Task: 451
// Link: https://leetcode.com/problems/sort-characters-by-frequency/

string frequencySort(string s) {
    unordered_map<char, int> myMap;
    for (char ch : s) {
        myMap[ch]++;
    }

    auto compare = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> myPQ(compare);

    for (auto freq : myMap) {
        myPQ.push({freq.first, freq.second});
    }

    string res;
    while (!myPQ.empty()) {
        size_t count = myPQ.top().second;
        while (count) {
            res += myPQ.top().first;
            count--;
        }
        myPQ.pop();
    }

    return res;
}

int main() {
    string s = "tree";
    cout << frequencySort(s) << endl;
    return 0;
}

