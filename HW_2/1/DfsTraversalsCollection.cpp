#include "DfsTraversalsCollection.h"

bool DfsTraversalsCollection::isValid(Traversal& traversal) const
{
	for (size_t i = 0; i < graphSize - 1; ++i) {

		int start = traversal.order[i];
		int end = traversal.order[i + 1];

		if (!graph.hasEdge(start, end)) {
			bool found = false;
			for (int j = i - 1; j >= 0; j--) {
				if (graph.hasEdge(traversal.order[j], end)) {
					found = true;
					break;
				}
			}
			if (!found) {
				return false;
			}
		}
	}
	return true;
}

void DfsTraversalsCollection::dfs(int vertex, Traversal& currentTraversal)
{
	visited[vertex] = true;
	currentTraversal.order.push_back(vertex);

	if (currentTraversal.order.size() == graph.size() && isValid(currentTraversal)) {
		traversals.push_back(currentTraversal);
	}
	else {
		for (size_t i = 0; i < graphSize; ++i) {
			if (!visited[i]) {
				dfs(i, currentTraversal);
			}
		}
	}
	visited[vertex] = false;
	currentTraversal.order.pop_back();
}

void DfsTraversalsCollection::sortTraversals()
{
	auto comp = [](const Traversal& a, const Traversal& b) {
		return a < b;
	};

	std::sort(traversals.begin(), traversals.end(), comp);
}

void DfsTraversalsCollection::generateTraversals(int startVertex)
{
	Traversal currentTraversal;
	dfs(startVertex, currentTraversal);
	sortTraversals();
	gatherTraversalInformation();
}

void DfsTraversalsCollection::findTreeEdges(Traversal& traversal)
{
	for (size_t i = 0; i < graphSize - 1; i++) {

		int start = traversal.order[i];
		int end = traversal.order[i + 1];

		if (graph.hasEdge(start, end)) {
			traversal.treeEdges.push_back({ start, end });
		}
		else {
			for (int j = i - 1; j >= 0; j--) {
				int backtrackStart = traversal.order[j];
				if (graph.hasEdge(backtrackStart, end)) {
					traversal.treeEdges.push_back({ backtrackStart, end });
					break;
				}
			}
		}
	}

}

void DfsTraversalsCollection::findBackEdges(Traversal& traversal)
{

	for (size_t i = 0; i < graphSize; i++) {

		int start = traversal.order[i];

		for (size_t j = 0; j <= i; j++)
		{
			int end = traversal.order[j];
			if (graph.hasEdge(start, end)) {
				traversal.backEdges.push_back({ start,end });
			}
		}
	}
}

void DfsTraversalsCollection::findForwardEdges(Traversal& traversal)
{
	for (size_t i = 0; i < graphSize; i++) {

		int start = traversal.order[i];

		for (size_t j = i + 2; j < graphSize; j++) {

			int end = traversal.order[j];
			if (graph.hasEdge(start, end)) {

				bool isTreeEdge = false;

				std::pair<int, int> forwardEdge = std::make_pair(start, end);
				for (const auto& treeEdge : traversal.treeEdges) {
					if (treeEdge == forwardEdge) {
						isTreeEdge = true;
						break;
					}
				}

				if (!isTreeEdge) {
					traversal.forwardEdges.push_back(forwardEdge);
				}
			}
		}
	}
}

void DfsTraversalsCollection::findCrossEdges(Traversal& traversal)
{
	
	for (size_t i = 0; i < graphSize; i++) {
		int start = traversal.order[i];

		for (size_t j = 0; j < graphSize; j++) {

			int end = traversal.order[j];
			if (i != j && graph.hasEdge(start, end)) {

				bool isAlreadyClassified = false;

				std::pair<int, int> crossEdge = std::make_pair(start, end);

				for (const auto& edge : traversal.backEdges) {
					if (edge == crossEdge) {
						isAlreadyClassified = true;
						break;
					}
				}

				for (const auto& edge : traversal.treeEdges) {
					if (edge == crossEdge) {
						isAlreadyClassified = true;
						break;
					}
				}

				for (const auto& edge : traversal.forwardEdges) {
					if (edge == crossEdge) {
						isAlreadyClassified = true;
						break;
					}
				}

				if (!isAlreadyClassified) {
					traversal.crossEdges.push_back(crossEdge);
				}

			}
		}
	}
}

DfsTraversalsCollection::DfsTraversalsCollection(const Graph& g, size_t startVertex) :graph(g), visited(g.size(), false), graphSize(g.size())
{
	generateTraversals(startVertex);
}


size_t DfsTraversalsCollection::getSize() const
{
	return traversals.size();
}

bool DfsTraversalsCollection::empty() const
{
	return getSize() == 0;
}

Iterator DfsTraversalsCollection::begin()
{
	return traversals.empty() ? Iterator(nullptr) : Iterator(&traversals[0]);
}

Iterator DfsTraversalsCollection::end()
{
	return traversals.empty() ? Iterator(nullptr) : Iterator(&traversals[0] + traversals.size());
}

ConstIterator DfsTraversalsCollection::cbegin() const
{
	return traversals.empty() ? ConstIterator(nullptr) : ConstIterator(&traversals[0]);
}

ConstIterator DfsTraversalsCollection::cend() const
{
	return traversals.empty() ? ConstIterator(nullptr) : ConstIterator(&traversals[0] + traversals.size());
}

void DfsTraversalsCollection::gatherTraversalInformation()
{
	for (auto& traversal : traversals) {
		findTreeEdges(traversal);
		findBackEdges(traversal);
		findForwardEdges(traversal);
		findCrossEdges(traversal);
	}
}
