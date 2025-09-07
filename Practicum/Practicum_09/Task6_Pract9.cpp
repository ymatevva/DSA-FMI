#include <iostream>
#include <vector>
#include <map>
using namespace std;

// LeetCode Problem: 2053 - Kth Distinct String in an Array
// Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/

string kthDistinct(vector<string>& arr, int k) {
    map<string, int> myMap;
    for (string str : arr) {
        myMap[str]++;
    }

    int count = 0;
    for (string str : arr) {
        if (myMap[str] == 1) {
            count++;
            if (count == k) {
                return str;
            }
        }
    }
    return "";
}

int main() {
    vector<string> arr = {"d", "b", "c", "b", "c", "a"};
    int k = 2;
    cout << kthDistinct(arr, k) << endl; // Output: "a"
    return 0;
}
