#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Leetcode: 1338
//leetcode.com/problems/reduce-array-size-to-the-half/description/?envType=problem-list-v2&envId=awdeugtv
//Complexity: O(n*logn)
int minSetSize(vector<int>& arr) {

    vector<int> countEl(100000, 0);
    for (long int i = 0; i < arr.size(); i++) {
        countEl[arr[i]]++;
    }

    long long sum = 0;
    long long count = 0;

    sort(countEl.begin(), countEl.end());
    for (long int i = countEl.size() - 1; i >= 0; i--) {

        if (countEl[i] != 0) {
            sum += countEl[i];
            count++;
        }
        if (sum >= arr.size() / 2) {
            return count;
        }

    }
    return count;
}


int main() {

    vector<int> vec = { 1,2,4,43,34,43,4,9,8,8,8,4,5,9 };
    std::cout << minSetSize(vec);
}