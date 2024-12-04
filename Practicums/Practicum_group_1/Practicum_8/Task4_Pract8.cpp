#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


//Leetcode: 1337
//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

size_t countSold(const vector<int>& vec) {
	size_t count = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 1) {
			count++;
		}
	}
	return count;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

	auto comp = [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
		int countA = countSold(a.second);
		int countB = countSold(b.second);
		return countA > countB || (countA == countB && a.first > b.first);
	};

	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(comp)> pq(comp);

	for (int i = 0; i < mat.size(); i++) {
		pq.push({ i, mat[i] });
	}

	vector<int> res;
	for (int i = 0; i < k; i++) {
		res.push_back(pq.top().first);
		pq.pop();
	}

	return res;
}

int main() {


	vector<vector<int>> mat = {
	 {1, 1, 0, 0, 0},
	 {1, 1, 1, 1, 0},
	 {1, 0, 0, 0, 0},
	 {1, 1, 0, 0, 0},
	 {1, 1, 1, 1, 1}
	};

	int k = 3;
	vector<int> result = kWeakestRows(mat, k);

	for (int num : result) {
		cout << num << " ";
	}
	cout << endl;

}