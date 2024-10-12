#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    vector<int> res;

    if(m == 0&& n == 1){
        nums1[0] = nums2[0];
    }
    if(m == 1 && n == 0){
        return;
    }
    size_t numsOneInd = 0;
    size_t numsTwoInd = 0;

    while(numsOneInd != m && numsTwoInd != n){

        if(nums1[numsOneInd]< nums2[numsTwoInd]){
            res.push_back(nums1[numsOneInd++]);
        }else if(nums1[numsOneInd]== nums2[numsTwoInd]){
            res.push_back(nums1[numsOneInd++]);
            res.push_back(nums2[numsTwoInd++]);

        }else{
            res.push_back(nums2[numsTwoInd++]);
        }
    }

    while(numsOneInd != m){
        res.push_back(nums1[numsOneInd++]);
    }

    while(numsTwoInd != n) {
        res.push_back(nums2[numsTwoInd++]);
    }
        nums1= res;

}
int main() {
    std::vector<int> vec1 = {1};
    std::vector<int> vec2 = {};

    merge(vec1, 1, vec2, 0);
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
}