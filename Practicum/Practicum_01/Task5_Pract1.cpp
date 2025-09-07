#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Leetcode: 1561
//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/?envType=problem-list-v2&envId=an1ryio3
//Complexity: O(n*logn)

int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());

    unsigned sizeOfPile = piles.size();
    unsigned startingPoint = sizeOfPile/3;//we skip the first n elements(they are for Bob)
    int res = 0;

    //now from the elements which are left we get the smaller element every round we play
    for(int i = startingPoint; i < sizeOfPile; i += 2){
        res+=piles[i];
    }
    return res;
}

int main(){

    vector<int>vec = {2,4,1,2,7,8};
    std::cout << maxCoins(vec);

}