#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Complexity: O(n*logn)
//Leetcode: 2144
//https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=problem-list-v2&envId=an1ryio3
int minimumCost(vector<int>& cost) {

    vector<int>sorted = cost;
    sort(sorted.begin(),sorted.end(),std::greater<int>());

    unsigned sum = 0;
    unsigned count = 0;
    for(int i = 0;i <= sorted.size()-1;i++){

        sum+=sorted[i];
        count++;
        if(count == 2){
            count = 0;
            i++;
        }
    }
    return sum;
}


int main() {

    vector<int>vec = {6,5,7,9,2,2};
    std::cout << minimumCost(vec);
}
