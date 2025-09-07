#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS_REC(const vector<vector<int>>& graph, vector<bool>&visited, int start) {

	visited[start] = true;
	for (const auto& iter : graph[start]) {
		if (!visited[iter]) {
			DFS_REC(graph, visited, iter);
		}
	}
}

int countConnectedComponents(const vector<vector<int>>& graph) {

	vector<bool>visited(graph.size(), false);

	size_t count = 0;
	for (size_t i = 0; i < graph.size(); i++)
	{
		if (!visited[i]) {
			count++;
			DFS_REC(graph, visited,i);
		}
	}
	return count;
}

int main() {
	vector<vector<int>> adjList(4);
	adjList[0] = { 1 };
	adjList[1] = { 3 };
	adjList[2] = { 3 };
	adjList[3] = { };

	std::cout <<  countConnectedComponents(adjList);
}