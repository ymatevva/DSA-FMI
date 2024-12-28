#include <iostream>
#include <vector>
#include <queue>
#include <stack>


class Graph {
	std::vector<std::vector<int>> adjList;
	bool oriented;

	void DFS_HELP(size_t start, std::vector<bool>& visited) const;
	
public:
	Graph(size_t vertexCount, bool isOriented);

	void addEdge(size_t start, size_t end);

	void BFS(size_t start) const;
	void DFS_ITERATIVE(size_t start) const;
	void DFS_RECURSIVE(size_t start) const;

};

void Graph::DFS_HELP(size_t start, std::vector<bool>& visited) const
{
	visited[start] = true;
	std::cout << start << " ";
	for (auto iter : adjList[start]) {
		if (!visited[iter]) {
			DFS_HELP(iter, visited);
		}
	}
}


void Graph::DFS_RECURSIVE(size_t start) const
{
	std::vector<bool>visited(adjList.size(), false);
	DFS_HELP(start, visited);
}



Graph::Graph(size_t vertexCount, bool isOriented) :adjList(vertexCount)
{
	this->oriented = isOriented;
}

void Graph::addEdge(size_t start, size_t end)
{
	adjList[start].push_back((int)end);
	if (!oriented) {
		adjList[end].push_back((int)start);
	}
}

void Graph::BFS(size_t start) const
{

	std::vector<bool> visited(adjList.size(), false);
	std::queue<size_t>myQ;
	myQ.push(start);
	visited[start];
	while (!myQ.empty()) {

		size_t curr = myQ.front();
		myQ.pop();
		std::cout << curr << " ";

		for (auto iter : adjList[curr]) {

			if (visited[iter]) {
				continue;
			}
			myQ.push(iter);
			visited[iter] = true;
		}
	}
}

void Graph::DFS_ITERATIVE(size_t start) const
{
	std::vector<bool>visited(adjList.size(), false);

	std::stack<size_t>myS;
	myS.push(start);

	while (!myS.empty()) {

		size_t curr = myS.top();
		myS.pop();
		
		if (visited[curr]) {
			continue;
		}

		visited[curr] = true;
		std::cout << curr << " ";

		for (auto iter : adjList[curr]) {
			myS.push(iter);
		}
	}
}

