#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// Task: Find Missing and Repeated Values in a Grid
// Link: https://leetcode.com/problems/find-missing-and-repeated-values/?envType=problem-list-v2&envId=a19800zg

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_map<int, int> myMap;
    size_t end = pow(grid.size(), 2);
    
    for (int i = 1; i <= end; i++) {
        myMap[i]++;
    } 

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            myMap[grid[i][j]]++;
        }
    }

    vector<int> res(2, 0);
    for (auto iter : myMap) {
        if (iter.second == 1) {
            res[1] = iter.first;
        }
        if (iter.second == 3) {
            res[0] = iter.first;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
    vector<int> result = findMissingAndRepeatedValues(grid);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
