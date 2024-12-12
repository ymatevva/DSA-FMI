#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


//Leetcode: 2103
//https://leetcode.com/problems/rings-and-rods/description/?envType=problem-list-v2&envId=a19800zg
    bool containsColours(const string& s) {
        bool isR = false, isG = false, isB = false;

        for(char ch : s){
            if(ch == 'B'){
                isB = true;
            }
            else if(ch == 'R'){
                isR = true;
            }
            else if(ch == 'G'){
                isG = true;
            }
        }

        int totalSum = (int)isG + (int)isB + (int)isR;
        return totalSum == 3;
    }

    int countPoints(string rings) {
        unordered_map<int, string> myMap;
        for(int i = 0; i < rings.size(); i += 2) {
            myMap[rings[i + 1] - '0'] += rings[i];
        }

        size_t count = 0;
        for(auto iter : myMap) {
            if(containsColours(iter.second)) {
                count++;
            }
        }
        return count;
    }


int main() {
    string rings2 = "B0R0G0R9G9B9";
    cout << "Result for rings2: " << countPoints(rings2) << endl;


    return 0;
}
