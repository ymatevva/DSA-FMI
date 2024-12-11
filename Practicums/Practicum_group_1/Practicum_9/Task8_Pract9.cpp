#include <vector>
#include <map>
using namespace std;

// Task: 532. K-diff Pairs in an Array
// Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

int findPairs(vector<int>& nums, int k) {
    map<int, int> myMap;
    for (int num : nums) {
        myMap[num]++;
    }

    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (k == 0) {
            if (myMap[nums[i]] > 1) {
                res++;
            }
            myMap.erase(nums[i] - k);
        } else {
            if (myMap.count(nums[i] - k)) {
                res++;
            }
            myMap.erase(nums[i] - k);
        }
    }
    return res;
}
