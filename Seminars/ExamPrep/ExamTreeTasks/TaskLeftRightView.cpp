#include<iostream>
#include<queue>
#include<vector>
using namespace std;


struct Node {
	int data;
	vector<Node*> children;
	Node(int data) :data(data) {}
};

vector<int>getLeftView(Node* root) {

	queue<Node*> myQ;
	myQ.push(root);

	vector<int> leftView;
	while (!myQ.empty()) {

		vector<int>currL;

		size_t currLSize = myQ.size();
		for (size_t i = 0; i < currLSize; i++)
		{
			auto topEl = myQ.front();
			myQ.pop();
			currL.push_back(topEl->data);

			for(int i = 0; i < topEl->children.size();i++){
				myQ.push(topEl->children[i]);
			}
		}
		if (!currL.empty())
		leftView.push_back(currL[0]);
	}
	return leftView;
}


vector<int>getRightView(Node* root) {

	queue<Node*> myQ;
	myQ.push(root);

	vector<int> rightView;
	while (!myQ.empty()) {

		vector<int>currL;

		size_t currLSize = myQ.size();
		for (size_t i = 0; i < currLSize; i++)
		{
			auto topEl = myQ.front();
			myQ.pop();
			currL.push_back(topEl->data);

			for (int i = 0; i < topEl->children.size(); i++) {
				myQ.push(topEl->children[i]);
			}
		}
		if(!currL.empty())
		rightView.push_back(currL[currL.size()-1]);
	}
	return rightView;
}

bool isSameFromBothSides(Node* root) {

	vector<int>leftV = getLeftView(root);
	vector<int>rightV = getRightView(root);

	return leftV == rightV;
}

int main() {
	
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

	
	std::cout << isSameFromBothSides(root) << std::endl;
}