#include<iostream>
#include<vector>

void smth(vector<int>& vec){

    int sizeVec = vec.size();
    for (int i = 1; i <= sizeVec; ++i) {
        for (int j = i; j <= sizeVec ; ++j) {
            //smth with O(1)
        }
    }
}

// Outer loop: 1 - sizeVec = > n
// Inner loop i - sizeVec = > O(n-i)
// => Sum 1 to sizeVec(n-i+1)
// +> O(n^2)