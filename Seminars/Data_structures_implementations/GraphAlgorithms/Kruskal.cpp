#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class UF {

	vector<int>parents;
	vector<int>sizes;
public:
	UF(size_t vCount) :parents(vCount), sizes(vCount, 1) {
		for (size_t i = 0; i < vCount; i++)
		{
			parents[i] = i;
		}
	}
	int getParent(int v) {
		if (parents[v] != v) {
			parents[v] = getParent(parents[v]);
		}
		return parents[v];
	}
	bool Union(int v1, int v2) {
		int par1 = getParent(v1);
		int par2 = getParent(v2);
		if (par1 == par2) {
			return false;
		}

		if (sizes[v1] > sizes[v2]) {
			swap(v1, v2);
		}

		parents[v1] = v2;
		sizes[v2] += sizes[v1];
		return true;
	}
};

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
	Graph(size_t vCount, bool isOr) :isOr(isOr), g(vCount) {}
	void addEdge(size_t from, size_t to, int weight) {
		g[from].push_back(make_pair(to, weight));
		if (!isOr) {
			g[to].push_back(make_pair(from, weight));
		}
	}
	int Kruskal(vector<Edge>& MST) {

		vector<Edge> edges;
		for (size_t i = 0; i < g.size(); i++)
		{
			for (size_t j = 0; j < g[i].size(); j++)
			{
				edges.emplace_back(i, g[i][j].first, g[i][j].second);
			}
		}

		sort(edges.begin(), edges.end());


		int mstWeight = 0;
		int edgesCount = 0;

		UF uf(g.size());

		for (size_t i = 0; i < edges.size(); i++)
		{
			if (edgesCount == g.size() - 1) {
				break;
			}

			auto& minEdge = edges[i];
			size_t from = minEdge.from;
			size_t to = minEdge.to;
			int weight = minEdge.weight;

			if (!uf.Union(from, to)) {
				continue;
			}

			MST.emplace_back(from, to, weight);
			mstWeight += weight;
			edgesCount++;

		}

		return mstWeight;
	}
};




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
	std::cout << "MST(Kruskal): " << g.Kruskal(MST) << std::endl;


}