#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode: 1710
//https://leetcode.com/problems/maximum-units-on-a-truck/?envType=problem-list-v2&envId=an1ryio3
//Complexity: O(n*logn)


int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

    vector<vector<int>> sorted = boxTypes;
    sort(sorted.begin(),sorted.end(),[](const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];//sorting them by their second arg in descending order
    });

    int countUnits = 0;
    int boxSizes = 0;

    for (int i = 0; i < boxTypes.size(); ++i) {

        if(boxSizes + sorted[i][0]  <= truckSize){
            countUnits += sorted[i][0] * sorted[i][1];
            boxSizes+=sorted[i][0];
        }
        else{
            for (int j = boxSizes; j < truckSize; ++j) {
                countUnits += sorted[i][1];
                boxSizes++;
            }
            break;
        }
    }
    return countUnits;
}
int main(){

    vector<vector <int>>vec = {{1,3},{2,2},{3,1}};
    std::cout << maximumUnits(vec,4);

    return 0;
}