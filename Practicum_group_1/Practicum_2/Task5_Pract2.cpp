#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Leetcode: 3111
//https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/?envType=problem-list-v2&envId=awdeugtv

//Complexity : O(n*logn)
int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {

    vector<vector<int>> sorted = points;
    sort(sorted.begin(), sorted.end(), [](const vector<int>& a, const vector<int>& b) {
        return  a[0] < b[0];
        });

    unsigned count = 0;

    for (int i = 0; i < sorted.size(); i++) {

        int smallestX = sorted[i][0];

        while (i + 1 < sorted.size() && sorted[i + 1][0] - smallestX <= w) {
            i++;
        }

        count++;

    }

    return count;
}

int main() {


    vector<vector<int>> vec = { {2,1} ,{1,0}, {1, 4},{1, 8},{3, 5},{4, 6} };
    std::cout << minRectanglesToCoverPoints(vec, 1);

    return 0;
}