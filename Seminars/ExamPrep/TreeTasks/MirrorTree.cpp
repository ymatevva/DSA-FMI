#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int data;
	vector<Node*> children;
	Node(int data) :data(data) { }
};

bool isTreeSeenTheSameFromBothSides(Node* root, vector<int>& view) {
	if (!root) {
		return false;
	}

	queue<Node*> myQ;
	myQ.push(root);

	while (!myQ.empty()) {

		vector<int>currLevel;

		size_t currLSize = myQ.size();
		for (size_t i = 0; i < currLSize; i++)
		{
			Node* topEl = myQ.front();
			myQ.pop();

			currLevel.push_back(topEl->data);

			for (auto& child : topEl->children) {
				myQ.push(child);
			}
		}
		if (currLevel[0] != currLevel[currLevel.size() - 1]) {
			return false;
		}
		view.push_back(currLevel[0]);
	}
}

int main()
{
	Node* root = new Node(5);

	root->children.push_back(new Node(3));
	root->children.push_back(new Node(9));
	root->children.push_back(new Node(3));

	root->children[0]->children.push_back(new Node(4));
	root->children[0]->children.push_back(new Node(3));
	root->children[0]->children.push_back(new Node(7));

	root->children[0]->children[2]->children.push_back(new Node(9));

	root->children[2]->children.push_back(new Node(5));
	root->children[2]->children.push_back(new Node(4));

	root->children[2]->children[0]->children.push_back(new Node(2));
	root->children[2]->children[1]->children.push_back(new Node(9));

	vector<int> view;
	bool result = isTreeSeenTheSameFromBothSides(root, view);
	cout << result << endl << endl;
	for (int i = 0; i < view.size(); i++)
		cout << view[i] << endl;

	delete root;
}