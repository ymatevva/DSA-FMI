#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool hasPathHelp(const vector<vector<int>>& vec, int start, int end, vector<bool>& visited) {

	if (start == end) {
		return true;
	}

	visited[start] = true;
	for (const auto& iter : vec[start]) {
		if (!visited[iter] && hasPathHelp(vec, iter, end, visited)) {
			return true;
		}
	}
	return false;
}

bool hasPath(const vector<vector<int>>& vec, int start, int end) {
	vector<bool>visited(vec.size(), false);

	return hasPathHelp(vec, start, end, visited);
}



int main() {
	vector<vector<int>> adjList(4);
	adjList[0] = { 1  };
	adjList[1] = { 3 };
	adjList[2] = { 3 };
	adjList[3] = { };

	std::cout << std::boolalpha << hasPath(adjList, 0, 2);
}