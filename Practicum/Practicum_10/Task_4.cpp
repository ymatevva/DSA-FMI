#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Leetcode: 797	

void dfsHelp(const 	vector<vector<int>>& adj, int start, int end, vector<int>& currPath, vector<vector<int>>& allPaths) {

	currPath.push_back(start);
	if (start == end) {
		allPaths.push_back(currPath);
	}
	
	for (const auto& neighbor : adj[start]) {
		
			dfsHelp(adj, neighbor, end, currPath, allPaths);
		
	}
	currPath.pop_back();
}
vector<vector<int>> generateAllPaths(const vector<vector<int>>& adj, int start, int end) {

	
	vector<int>currPath;
	vector<vector<int>> allPaths;
	dfsHelp(adj, start, end, currPath, allPaths);
	return allPaths;
}



int main() {

	vector<vector<int>> adj(4);
	adj[0] = { 1,2 };
	adj[1] = { 3 };
	adj[2] = { 3 };
	adj[3] = {};

	vector<vector<int>> allPaths = generateAllPaths(adj,0, 3);

	for (const auto& path : allPaths) {
		for (const auto& iter : path) {
			std::cout << iter << " ";
		}
		std::cout << std::endl;
	}
}