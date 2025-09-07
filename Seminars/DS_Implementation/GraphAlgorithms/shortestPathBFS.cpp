#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int shortestPath(const vector<vector<int>>& vec, int start, int end) {

	vector<bool> visited(vec.size(), false);
	queue<int>myQ;

	int dist = 0;

	myQ.push(start);
	visited[start] = true;

	while (!myQ.empty()) {

		size_t currQSize = myQ.size();
		for (size_t i = 0; i < currQSize; i++)
		{
			int topEl = myQ.front();
			myQ.pop();

			for (const auto& neighbor : vec[topEl]) {
				if (!visited[neighbor]) {
					if (neighbor == end) {
						return dist + 1;
					}

					myQ.push(neighbor);
					visited[neighbor] = true;
				}	
			}
		}
		dist++;
	}
	return -1;
}

int main() {
	vector<vector<int>> adjList(4);
	adjList[0] = { 1 ,2 };
	adjList[1] = { 3 };
	adjList[2] = { 3 };
	adjList[3] = { };

	std::cout << std::boolalpha << shortestPath(adjList,0,3);
}