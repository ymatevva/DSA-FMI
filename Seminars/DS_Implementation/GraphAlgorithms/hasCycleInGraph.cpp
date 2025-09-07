#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;


bool hasCycleHelp(const vector<vector<int>>& graph, int start,vector<bool>& visited, vector<bool>& inStack) {

	if (!visited[start]) {
		visited[start] = true;
		inStack[start] = true;//we mark it as visited

		for (const auto& neighbor : graph[start])
		{
			if (!visited[neighbor] && hasCycleHelp(graph, neighbor, visited, inStack)) {
				return true;
			}
			if (inStack[neighbor]) {
				return true;//we take this if as the bottom
			}
		}
	}
	inStack[start] = false;
	return false;//if we havent found cycle from start we proceed to the next vertex
}

bool hasCycle(const vector<vector<int>>& graph) {

	vector<bool> visited(graph.size(), false);
	vector<bool> inStack(graph.size(), false);

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (hasCycleHelp(graph, i, visited, inStack)) {
			return true;//if one of these vertexes goes to another one in the stack then we have cycle
		}
	}
	return false;
}

int main() {
	vector<vector<int>> adjList(4);
	adjList[0] = { 1 ,2};
	adjList[1] = { 3 };
	adjList[2] = { 3 };
	adjList[3] = { };

	std::cout << std::boolalpha << hasCycle(adjList);
}