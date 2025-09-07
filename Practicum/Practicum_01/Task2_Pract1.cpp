#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Leetcode: 1051
//https://leetcode.com/problems/height-checker/description/?envType=problem-list-v2&envId=an1ryio3


int heightChecker(vector<int>& heights) {

    vector<int> sorted = heights;
    sort(heights.begin(),heights.end());

    unsigned count =0;
    for(int i = 0; i < sorted.size();i++){
        if(heights[i]!=sorted[i]){
            count++;
        }
    }
    return count;

    //complexity: O(nlogn), bc of the sort function
}
int main(){

    vector<int>vec = {1,8,3,4,5,9};
    std::cout << heightChecker(vec);

    return 0;
}