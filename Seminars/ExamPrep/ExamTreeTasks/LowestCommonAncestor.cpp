#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;



vector<int>getPath(vector<int>& parents, int node) {

	vector<int>path;
	while (node != -1) {
		path.push_back(node);
		node = parents[node];
	}
	return path;
}



int LCA(vector<int>& parents, int node1, int node2) {

	vector<int>path1 = getPath(parents, node1);
	vector<int>path2 = getPath(parents, node2);

	unordered_set<int>mySet(path1.begin(), path1.end());

	for (auto& it : path2) {
		if (mySet.count(it)) {
			return it;
		}
	}
	return -1;
}






int main() {

	vector<int>parents = { -1, 0, 0, 1, 1, 2, 2 };
	std::cout << LCA(parents, 5, 6);
}