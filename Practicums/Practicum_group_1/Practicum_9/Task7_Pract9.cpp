// LeetCode Task: 2006. Count Number of Pairs With Absolute Difference K
// Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int countKDifference(vector<int>& nums, int k) {
    int res = 0;
    map<int, int> myMap;
    for (int num : nums) {
        myMap[num]++;
    }
    for (auto pair : myMap) {
        if (myMap.count(pair.first + k)) {
            res += pair.second * myMap[pair.first + k];
        }
    }
    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    int k1 = 1;
    cout << countKDifference(nums1, k1) << endl;

    vector<int> nums2 = {1, 3, 1, 5, 4};
    int k2 = 2;
    cout << countKDifference(nums2, k2) << endl;

    return 0;
}
