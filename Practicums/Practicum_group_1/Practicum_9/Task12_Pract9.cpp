#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Task: 2399
// Link: https://leetcode.com/problems/check-distances-between-same-letters/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> stringSymb;
        for (int i = 0; i < s.size(); i++) {
            if (!stringSymb[s[i]]) {
                stringSymb[s[i]] = i + 1;
            } else {
                stringSymb[s[i]] = i - stringSymb[s[i]];
            }
        }

        for (auto pair : stringSymb) {
            if (pair.second != distance[pair.first - 'a']) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "abaccb";
    vector<int> distance = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool result = solution.checkDistances(s, distance);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
