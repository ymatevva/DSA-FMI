
#include <vector>
#include <unordered_map>
using namespace std;

// Task: 2956
// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;

    for (int num : nums1) {
        map1[num]++;
    }

    for (int num : nums2) {
        map2[num]++;
    }

    size_t foundIn2 = 0;
    size_t foundIn1 = 0;

    for (int i = 0; i < nums1.size(); i++) {
        if (map1[nums1[i]] && map2[nums1[i]]) {
            foundIn2 += map2[nums1[i]];
            foundIn1 += map1[nums1[i]];
            map1[nums1[i]] = 0;
            map2[nums1[i]] = 0;
        }
    }

    vector<int> res(2, 0);
    res[1] = foundIn2;
    res[0] = foundIn1;
    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 2, 3, 4};
    vector<int> result = findIntersectionValues(nums1, nums2);

    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
