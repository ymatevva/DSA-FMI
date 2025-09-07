#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
	vector<bool>visited(graph.size(), false);
	queue<int>myQ;

	myQ.push(start);
	visited[start] = true;

	while (!myQ.empty()) {

		int topEl = myQ.front();
		myQ.pop();

		std::cout << topEl << " ";

		for (const auto& iter : graph[topEl]) {
			if (!visited[iter]) {
				myQ.push(iter);
				visited[iter] = true;
			}
		}
	}
}

int main() {

	vector<vector<int>> adjList(4);
	adjList[0] = { 1,2 };
	adjList[1] = { 3 };
	adjList[2] = { 1,3 };
	adjList[3] = { 0 };
	BFS(adjList,2);
}