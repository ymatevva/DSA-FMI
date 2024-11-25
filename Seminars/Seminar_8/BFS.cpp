#include<iostream>
#include<queue>
#include<vector>

struct Node {

	char data;
	std::vector<Node*>children;
};

void BFS(const Node* root) {

	if (!root) {
		return;
	}

	std::queue<const Node*> myQ;
	myQ.push(root);

	while (!myQ.empty()) {

		size_t currSize = myQ.size();

		for (size_t i = 0; i < currSize; i++)
		{
			std::cout << myQ.front()->data << " ";

			for (size_t i = 0; i < myQ.front()->children.size(); i++)
			{
				myQ.push(myQ.front()->children[i]);
			}
			myQ.pop();
		}
		std::cout << std::endl;
	
	}
}

void free(Node* root) {
	if (!root)
	{
		return;
	}

	for (size_t i = 0; i < root->children.size(); i++)
	{
		free(root->children[i]);
	}
	delete root;
}
int main() {

	Node* root = new Node{ 'a' };

	root->children.push_back(new Node{ 'b' });
	root->children.push_back(new Node{ 'c' });
	root->children.push_back(new Node{ 'd' });
	root->children.at(0)->children.push_back(new Node{ 'x' });
	root->children.at(0)->children.push_back(new Node{ 'y' });

	BFS(root);

	return 0;
}
