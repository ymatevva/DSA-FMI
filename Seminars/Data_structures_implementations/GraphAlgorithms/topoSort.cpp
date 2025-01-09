#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topoSortHelp(const vector<vector<int>>& graph, vector<bool>& visited, int start,vector<int>&sortedGraph) {
	visited[start] = true;

	for (const auto& iter : graph[start]) {
		if (!visited[iter]) {
			topoSortHelp(graph, visited, iter,sortedGraph);
		}
	}
	sortedGraph.push_back(start);
}

vector<int> topoSort(const vector<vector<int>>& graph) {

	vector<int> sortedGraph;
	vector<bool>visited(graph.size(), false);

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (!visited[i]) {
			topoSortHelp(graph, visited, i,sortedGraph);
		}
	}

	reverse(sortedGraph.begin(), sortedGraph.end());
	return sortedGraph;
}

int main() {
	vector<vector<int>> adjList = {
		  {1, 2}, 
		  {3},    
		  {3},   
		  {}     
	};

	vector<int> result = topoSort(adjList);
	
	for (int node : result) {
		cout << node << " ";
	}
}