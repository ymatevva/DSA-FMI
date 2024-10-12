#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int dominantIndex(vector<int>& nums) {

    int maxEl = INT_MIN;
    unsigned maxElInd = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > maxEl){
            maxEl = nums[i];
            maxElInd = i;
        }
    }

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    for(int i = sorted.size()-2; i >=0;i--){
        if(!(maxEl >= 2*sorted[i])){
            return -1;
        }
    }
    return maxElInd;
}
int main()
{
   vector<int> vec{1,6 ,3,0};

   std :: cout << dominantIndex(vec);

    return 0;
}