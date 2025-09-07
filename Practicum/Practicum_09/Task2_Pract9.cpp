#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


//Leetcode: 1512
//https://leetcode.com/problems/number-of-good-pairs/description/

int numIdenticalPairs(vector<int>& nums) {

    unordered_map<int, int> myMap;
    unsigned count = 0;
    for (int num : nums) {
        if (myMap[num] != 0) {
            count += myMap[num];
        }
        myMap[num]++;

    }
    return count;
}


int main() {
  
    vector<int> vec = { 1,2,3,1,1,3 };
    std::cout << numIdenticalPairs(vec);

	return 0;
}