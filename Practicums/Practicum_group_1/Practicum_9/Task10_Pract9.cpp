#include <vector>
#include <unordered_map>
using namespace std;

// Task: 2215
// Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map1;
    for (int num : nums1) {
        map1[num]++;
    }

    unordered_map<int, int> map2;
    for (int num : nums2) {
        map2[num]++;
    }

    vector<int> notIn1;
    vector<int> notIn2;

    for (auto iter : map1) {
        if (!map2[iter.first]) {
            notIn2.push_back(iter.first);
            iter.second = 0;
        }
    }
    for (auto iter : map2) {
        if (!map1[iter.first]) {
            notIn1.push_back(iter.first);
            iter.second = 0;
        }
    }

    vector<vector<int>> res;
    res.push_back(notIn2);
    res.push_back(notIn1);
    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> result = findDifference(nums1, nums2);

    for (const auto& vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
