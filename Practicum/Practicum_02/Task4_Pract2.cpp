#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode: 1509
//https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=problem-list-v2&envId=awdeugtv


//Complexity: (n*logn)
int minDifference(vector<int>& nums) {

    vector<int> res = nums;
    sort(res.begin(), res.end());

    if (res.size() >= 5) {
        int firstWay = res[res.size() - 3] - res[1];//removing th etwo biggest and the smallest
        int secWay = res[res.size() - 2] - res[2];//removing the biggest and two of the smallest in asc
        int thirdWay = res[res.size() - 1] - res[3];//removing the three smallest
        int fourthWay = res[res.size() - 4] - res[0];//removing the three biggest

        return std::min(std::min(firstWay, secWay), std::min(thirdWay, fourthWay));
    }

    return 0;

}

int main() {

    vector<int>vec = { 5,4,2,3 };
    std::cout << minDifference(vec);

    return 0;
}