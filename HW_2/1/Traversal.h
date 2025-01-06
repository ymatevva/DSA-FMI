#pragma once
#include<vector>
#include<ostream>

struct Traversal {
private:
	std::vector<int> order;
	std::vector<std::pair<int, int>> treeEdges;
	std::vector<std::pair<int, int>> forwardEdges;
	std::vector<std::pair<int, int>> backEdges;
	std::vector<std::pair<int, int>> crossEdges;
	friend class DfsTraversalsCollection;
public:
	const std::vector<std::pair<int, int>>& getTreeEdges() const;
	const std::vector<std::pair<int, int>>& getBackEdges() const;
	const std::vector<std::pair<int, int>>& getForwardEdges() const;
	const std::vector<std::pair<int, int>>& getCrossEdges() const;
	friend bool operator<(const Traversal& lhs, const Traversal& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Traversal& obj);
};
