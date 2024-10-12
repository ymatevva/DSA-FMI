#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    vector<vector<int>> res;

    int minDiff = INT_MAX;
    for (int i = 0; i < sorted.size()-1; i++)
    {
        int curDiff = sorted[i + 1] - sorted[i];
        if (curDiff < minDiff) {
            minDiff = curDiff;
        }
    }

    for (size_t i = 0; i < sorted.size()-1; i++)
    {
        int curDiff = sorted[i + 1] - sorted[i];
        if (curDiff == minDiff) {
            res.push_back({ sorted[i],sorted[i + 1] });
        }
    }
    return res;
}
int main() {

    vector<int> vec = { 1,3,6,10,15 };
    vector<vector<int>> res = minimumAbsDifference(vec);

    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i][0] << res[i][1] << std::endl;
    }

    return 0;
}