#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip> 
using namespace std;

struct Edge {
	size_t from;
	size_t to;
	int weight;
	Edge(size_t from, size_t to, int weight) :from(from), to(to), weight(weight) {}
	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
	bool operator>(const Edge& other) const {
		return weight > other.weight;
	}
};

class Graph {
	bool isOr;
	vector<vector<pair<size_t, int>>> g;
public:
	Graph(size_t vCount, bool isOr) :isOr(isOr), g(vCount) {};
	void addEdge(size_t from, size_t to, int weight) {
		g[from].push_back(make_pair(to, weight));
		if (!isOr) {
			g[to].push_back(make_pair(from, weight));
		}
	}
	int Prim(vector<Edge>& MST) {

			priority_queue<Edge, vector<Edge>, std::greater<>> myPQ;
			vector<bool>visited(g.size(), false);

			bool isFirstVisited = false;
			int mstWeight = 0;
			int countEdges = 0;

			myPQ.push({ 0,0,0 });

			while (countEdges < g.size() - 1) {
				auto minEdge = myPQ.top();
				myPQ.pop();

				size_t from = minEdge.from;
				size_t to = minEdge.to;
				int weight = minEdge.weight;

				if (visited[to]) {
					continue;
				}
				visited[to] = true;

				for (int i = 0; i < g[to].size(); i++)
				{
					myPQ.push({ to,g[to][i].first,g[to][i].second });
				}

				if (!isFirstVisited) {
					isFirstVisited = true;
					continue;
				}
				MST.emplace_back( from, to, weight );
				mstWeight += weight;
				countEdges++;
				isFirstVisited = true;
			}
			return mstWeight;
	}
	
};


void printEdge(const Edge& edge) {
	std::cout << edge.from << " " << edge.to << " " << edge.weight << std::endl;
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

		std::vector<Edge> MST;
		std::cout << "MST(Prim): " << g.Prim(MST) << std::endl;
		std::cout << "Edges: " << std::endl;

		for (int i = 0; i < MST.size(); i++)
			printEdge(MST[i]);
		std::cout << std::endl << std::endl << std::endl;


}