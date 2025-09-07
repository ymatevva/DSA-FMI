#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip> 
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
	bool isOriented;
	vector<vector<pair<int, int>>> adj;
public:
	Graph(int vertexCount, bool isOriented);
	void addEdge(int start, int end, int weight);
	int djikstra(int start, int end, vector<int>& path);
};

Graph::Graph(int vertexCount, bool isOriented) :adj(vertexCount), isOriented(isOriented)
{
}

void Graph::addEdge(int start, int end, int weight)
{
	adj[start].push_back({ end,weight });
	if (!isOriented) {
		adj[end].push_back({ start,weight });
	}
}

int Graph::djikstra(int start, int end, vector<int>& path)
{
	vector<int>distances(adj.size(), INT_MAX);
	vector<int>prevs(adj.size());

	struct VertexAndDist {
		int vertex;
		int dist;
		bool operator<(const VertexAndDist& other) const {
			return dist > other.dist;
		}
	};

	priority_queue<VertexAndDist>myPQ;
	myPQ.push({ start,0 });
	distances[start] = 0;

	while (!myPQ.empty()) {

		VertexAndDist curr = myPQ.top();
		myPQ.pop();


		if (curr.vertex == end) {

			while (end != start) {
				path.push_back(end);
				end = prevs[end];
			}

			path.push_back(start);
			reverse(path.begin(), path.end());
			return distances[curr.vertex];
		}


		for (auto iter : adj[curr.vertex]) {

			int currDist = curr.dist;
			int currEl = curr.vertex;
			int nextDist = iter.second;
			int nextEl = iter.first;

			if (currDist + nextDist < distances[nextEl]) {
				distances[nextEl] = currDist + nextDist;
				myPQ.push({ nextEl,currDist + nextDist });
				prevs[nextEl] = currEl;
			}
		}
	}

	return INT_MAX;

}



int main()
{
	Graph g(9, false);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(1, 2, 8);
	g.addEdge(7, 8, 7);
	g.addEdge(7, 6, 1);
	g.addEdge(8, 6, 6);
	g.addEdge(8, 2, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(6, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);
	g.addEdge(5, 4, 10);

	std::vector<int> path;
	std::cout << g.djikstra(0, 4, path) << std::endl;
	std::cout << "Path : ";
	for (int i = 0; i < path.size(); i++)
		std::cout << path[i] << " ";
	std::cout << std::endl << std::endl << std::endl;
}