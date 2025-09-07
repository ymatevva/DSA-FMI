#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode: 2824
//https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/?envType=problem-list-v2&envId=awdeugtv

int countPairs(vector<int>& nums, int target) {

    unsigned count = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size();j++){
            if(nums[i]+nums[j]<target){
                count++;
            }
        }
    }
    return count;
}
int main(){

    vector<int>vec = {-1,1,2,3,1};
    std::cout << countPairs(vec,2);
    return 0;
}