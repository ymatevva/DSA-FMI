#include<iostream>
#include<vector>
#include<queue>

using namespace std;


//Leetcode: 973
//https://leetcode.com/problems/k-closest-points-to-origin/submissions/1470169693/


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

    for (int i = 0; i < points.size(); i++) {
        int  dist = pow(points[i][0], 2) + pow(points[i][1], 2);
        pq.push({ dist,i });
    }


    vector<vector<int>> closest;
    for (int i = 0; i < k; i++) {
        closest.push_back(points[pq.top().second]);
        pq.pop();
    }

    return closest;
}

int main() {
    vector<vector<int>> points = { {1, 3}, {-2, 2}, {5, 8}, {0, 1} };
    int k = 2;

    vector<vector<int>> result = kClosest(points, k);

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
}