#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


//Leetcode: 771
//https://leetcode.com/problems/jewels-and-stones/

int numJewelsInStones(string jewels, string stones) {

    unordered_map<char, int> mapJew;

    for (char ch : jewels) {
        mapJew[ch]++;
    }

    size_t count = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (mapJew[stones[i]] != 0) {
            count++;
        }
    }
    return count;
}


int main() {
  
	string str1 = "aA";
	string str2 = "aAAbbbb";

    std::cout << numJewelsInStones(str1, str2);

	return 0;
}