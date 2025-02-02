#include<iostream>
#include<queue>
#include<vector>
using namespace std;


struct Node {
	int data;
	vector<Node*> children;
	Node(int data) :data(data) {}
	~Node() {
		for (size_t i = 0; i < children.size(); i++)
		{
			delete children[i];
		}
	}
};

void getLongestPrettyPath(Node* root, vector<int>& path)
{
	vector<int>longestPP;
	path.push_back(root->data);

	for (size_t i = 0; i < root->children.size(); i++)
	{
		if (!root->children[i]->data || (!(root->data % root->children[i]->data))) { continue; }

		vector<int>tmpPath;
		getLongestPrettyPath(root->children[i], tmpPath);

		if (tmpPath.size() > longestPP.size()) {
			longestPP = tmpPath;
		}
	}

	path.insert(path.end(), longestPP.begin(), longestPP.end());
}

int main()
{
	Node* root = new Node(10);
	root->children.push_back(new Node(3));
	root->children.push_back(new Node(5));
	root->children.push_back(new Node(15));

	root->children[0]->children.push_back(new Node(9));
	root->children[1]->children.push_back(new Node(7));

	vector<int> path;
	getLongestPrettyPath(root, path);

	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";

	delete root;
}