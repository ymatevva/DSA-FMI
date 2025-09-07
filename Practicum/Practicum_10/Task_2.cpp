#include<iostream>
#include<vector>
using namespace std;


void DFS_REC(const vector<vector<int>>& graph, vector<bool>& visited, int start, double& currSum, double& countEl) {

	currSum += start;
	countEl++;
	visited[start] = true;
	for (const auto& iter : graph[start]) {
		if (!visited[iter]) {
			DFS_REC(graph, visited, iter, currSum, countEl);
		}
	}
}
double sumAvgOfConnectedComp(const vector<vector<int>>& graph) {

	vector<bool>visited(graph.size(), false);

	double totalSum = 0;

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (!visited[i]) {
			double currSum = 0;
			double countEl = 0;
			DFS_REC(graph, visited, i, currSum, countEl);
			totalSum += (currSum / countEl);
		}
	}
	return totalSum;
}

int main() {

	vector<vector<int>> adj(9);
	adj[0] = { 1, 3 };
	adj[1] = { 0, 2, 3 };
	adj[2] = { 1, 3 };
	adj[3] = { 0, 1, 2 };
	adj[4] = { 5, 6 };
	adj[5] = { 4, 6 };
	adj[6] = { 4, 5 };
	adj[7] = { 8 };
	adj[8] = { 7 };
	std::cout << sumAvgOfConnectedComp(adj);
}