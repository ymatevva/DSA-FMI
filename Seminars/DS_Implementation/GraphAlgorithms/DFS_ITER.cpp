#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;


void DFS_ITER(const vector<vector<int>>& adj, int start) {

	vector<bool>visited(adj.size(), false);
	stack<int>mySt;

	mySt.push(start);
	visited[start] = true;

	while (!mySt.empty()) {

		int topEl = mySt.top();
		mySt.pop();

		std::cout << topEl << " ";
		
		for (const auto& iter : adj[topEl]) {
			if (!visited[iter]) {
				mySt.push(iter);
				visited[iter] = true;
			}
		}
	}
}

void DFS_ITER_WEIGHTED(const vector<vector<pair<int,int>>>& adj, int start) {

	vector<bool>visited(adj.size(), false);
	stack<int>mySt;

	mySt.push(start);
	visited[start] = true;

	while (!mySt.empty()) {

		int topEl = mySt.top();
		mySt.pop();

		std::cout << topEl << " ";

		for (const auto& iter : adj[topEl]) {
			if (!visited[iter.first]) {
				mySt.push(iter.first);
				visited[iter.first] = true;
			}
		}
	}
}

int main() {

	vector<vector<int>> adjList(4);
	adjList[0] = { 1,2 };
	adjList[1] = { 3 };
	adjList[2] = { 1,3 };
	adjList[3] = { };

	DFS_ITER(adjList, 0);
	std::cout << std::endl;

	vector<vector<pair<int, int>>> weightedGraph = {
	   {{1, 4}, {2, 1}},      // Node 0 connects to Node 1 (weight 4), Node 2 (weight 1)
	   {{3, 1}},              // Node 1 connects to Node 3 (weight 1)
	   {{1, 2}, {3, 5}},      // Node 2 connects to Node 1 (weight 2), Node 3 (weight 5)
	   {{}}                   // Node 3 has no outgoing edges
	};
	DFS_ITER_WEIGHTED(weightedGraph, 1);
} 