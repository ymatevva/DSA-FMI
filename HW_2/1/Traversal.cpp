#include"Traversal.h"

const std::vector<std::pair<int, int>>& Traversal::getTreeEdges() const
{
	return treeEdges;
}

const std::vector<std::pair<int, int>>& Traversal::getBackEdges() const
{
	return backEdges;
}

const std::vector<std::pair<int, int>>& Traversal::getForwardEdges() const
{
	return forwardEdges;
}

const std::vector<std::pair<int, int>>& Traversal::getCrossEdges() const
{
	return crossEdges;
}

bool operator<(const Traversal& lhs, const Traversal& rhs)
{
	return lhs.order < rhs.order;
}

std::ostream& operator<<(std::ostream& os, const Traversal& obj)
{
	for (size_t i = 0; i < obj.order.size(); i++)
	{
		os << obj.order[i];
		if (i < obj.order.size() - 1) {
			os << " ";
		}
	}
	return os;
}
