#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode: 976
//https://leetcode.com/problems/largest-perimeter-triangle/?envType=problem-list-v2&envId=an1ryio3
//Complexity: O(n*logn)

int largestPerimeter(vector<int>& nums) {

    vector<int>sorted = nums;
    sort(sorted.begin(),sorted.end(),std::greater<int>());

    for (int i = 0; i < sorted.size()-2; ++i) {

        int largestSide = sorted[i];
        if(largestSide < sorted[i-1]+sorted[i-2]){
            return largestSide + sorted[i+1]+sorted[i+2];
        }
    }

    return 0;
}

int main(){

    vector<int>vec={2,1, 2};
    std::cout << largestPerimeter(vec);

    return 0;
}