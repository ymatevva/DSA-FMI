#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"
#include"Traversal.h"
#include "Iterators.h"

using namespace std;

class DfsTraversalsCollection {

	const Graph& graph;
	size_t graphSize;
	std::vector<bool> visited;
	std::vector<Traversal> traversals;

	bool isValid(Traversal& traversal) const;
	void dfs(int vertex, Traversal& currentTraversal);

	void sortTraversals();
	void gatherTraversalInformation();
	void generateTraversals(int startVertex);

	void findTreeEdges(Traversal& traversal);
	void findBackEdges(Traversal& traversal);
	void findForwardEdges(Traversal& traversal);
	void findCrossEdges(Traversal& traversal);
public:
	DfsTraversalsCollection(const Graph& g, size_t startVertex);

	size_t getSize()const;
	bool empty() const;
	 
	Iterator begin();
	Iterator end();

	ConstIterator cbegin()const;
	ConstIterator cend() const;
};
