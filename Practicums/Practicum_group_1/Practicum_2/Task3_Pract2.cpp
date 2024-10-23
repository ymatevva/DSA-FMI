#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Complexity: O(n*logn)
//Leetcode: 973
//https://leetcode.com/problems/k-closest-points-to-origin/?envType=problem-list-v2&envId=awdeugtv

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    vector<vector<int>> sorted = points;
    sort(sorted.begin(), sorted.end(), [](const vector<int>& a, const vector<int>& b) {

        return  1 << a[0] + 1 << a[1] < 1 << b[0] + 1 << b[1];
        });


        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(sorted[i]);
        }

        return res;
}

int main() {

    vector<vector<int>> ves = { {1,3},{-2,2} };
    vector<vector<int>> res  = kClosest(ves, 1);
     
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i][0] << res[i][1] << " ";
    }

    return 0;
}