// Custom Task: Find Permutation Difference
// Description: Calculates the sum of index differences between two strings' characters in permutation mappings.

#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

int findPermutationDifference(string s, string t) {
    unordered_map<char, int> mapS;
    unordered_map<char, int> mapT;

    for (int i = 0; i < s.size(); i++) {
        mapS[s[i]] = i;
    }

    for (int i = 0; i < t.size(); i++) {
        mapT[t[i]] = i;
    }

    size_t count = 0;
    for (int i = 0; i < s.size(); i++) {
        count += abs(mapS[s[i]] - mapT[t[i]]);
    }

    return count;
}

int main() {
    string s = "abcde";
    string t = "edcba";
    int result = findPermutationDifference(s, t);
    cout << "Permutation Difference: " << result << endl;
    return 0;
}
