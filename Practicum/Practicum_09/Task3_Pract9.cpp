#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


//Leetcode: 1941
//https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

bool areOccurrencesEqual(string s) {
    unordered_map<char, int>myMap;
    for (char ch : s) {
        myMap[ch]++;
    }


    int firstOcc = myMap.begin()->second;
    for (auto pair : myMap) {
        int currOcc = pair.second;
        if (currOcc != firstOcc) {
            return false;
        }
    }
    return true;
}


int main() {
  
    string str = "aabbccg";
    std::cout << areOccurrencesEqual(str);
	return 0;
}