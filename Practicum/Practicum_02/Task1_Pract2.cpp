#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode : 2587
//https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/?envType=problem-list-v2&envId=awdeugtv

int maxScore(vector<int>& nums) {

    vector<int> sorted = nums;
    sort(nums.begin(),nums.end(),std::greater<int>());

    unsigned countPositive = 0;
    int countSum = 0;

    for (int i = 0; i < sorted.size() ; ++i) {

        if(countSum + sorted[i] > 0){
            return countPositive;
        }else{
            countSum+=sorted[i];
            countPositive++;
        }
    }
    return countPositive;
}


int main(){

    vector<int>vec = {2,-1,0,1,-3,3,-3};
    std::cout << maxScore(vec);

}

