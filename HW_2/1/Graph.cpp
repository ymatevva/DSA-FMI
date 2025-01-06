#include "Graph.h"

Graph::Graph(size_t size) :adj(size)
{
}

void Graph::addEdge(int start, int end)
{
    adj[start].push_back(end);
}

size_t Graph::size() const
{
    return adj.size();
}

bool Graph::hasEdge(int start, int end) const
{
	for (int i = 0; i < adj[start].size(); i++)
	{
		if (adj[start][i] == end) {
			return true;
		}
	}
	return false;
}
