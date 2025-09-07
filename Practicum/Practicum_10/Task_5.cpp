#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Leetcode: 841 https://leetcode.com/problems/keys-and-rooms/description/

void dfsVisit(const vector<vector<int>>& adj, int start,vector<bool>&visited) {

	visited[start] = true;
	for (auto it : adj[start]) {
		if (!visited[it]) {
			dfsVisit(adj,it,visited);
		}
	}
}

bool canVisitAllFromStart(const vector<vector<int>>& adj, int start) {

	vector<bool>visited(adj.size(), false);

	dfsVisit(adj, start, visited);

	for (auto it : visited) {
		if (!it) {
			return false;
		}
	}
	return true;
}

int main() {

	vector<vector<int>> adj(4);
	adj[0] = { 1 };
	adj[1] = { 2};
	adj[2] = { 3 };
	adj[3] = {};

	std :: cout <<	 canVisitAllFromStart(adj, 0);
}