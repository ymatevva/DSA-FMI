#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

struct Node {

	char data;
	std::vector<Node*>children;
};


void DFS(Node* root, std::string& str) {
	if (!root) {
		return;
	}

	str.push_back(root->data);
	if (!root->children.size()) {
		std::cout << str << std::endl;
	}

	for (size_t i = 0; i < root->children.size(); i++)
	{
		DFS(root->children[i], str);
	}

	str.pop_back();

}

void free(Node* root) {
	if (!root) {
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

	std::string str;
	DFS(root,str);

	return 0;
}