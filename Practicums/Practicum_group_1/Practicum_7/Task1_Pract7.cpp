#include<iostream>

//Leetcode 226:
//https://leetcode.com/problems/invert-binary-tree/description/?envType=problem-list-v2&envId=awtrxc3t

struct TNode {
	int val;
	TNode* left;
	TNode* right;
	TNode(int val) :val(val), left(nullptr), right(nullptr) {}
};

TNode* invertBT(TNode* root) {

	if (!root) {
		return nullptr;
	}

	TNode* leftTmp = root->left;
	TNode* rightTmp = root->right;

	root->left = rightTmp;
	root->right = leftTmp;

	invertBT(root->left);
	invertBT(root->right);

	return root;
}

void printBT(TNode* root) {
	if (!root) {
		return;
	}

	std::cout << root->val << " ";
	printBT(root->left);
	printBT(root->right);
}

void freeBT(TNode* root) {
	if (!root) {
		return;
	}

	freeBT(root->left);
	freeBT(root->right);

	delete root;
}
int main() {

	TNode* root = new TNode(4);
	root->left = new TNode(2);
	root->right = new TNode(7);
	root->left->left = new TNode(1);
	root->left->right = new TNode(3);
	root->right->left = new TNode(6);
	root->right->right = new TNode(9);

	invertBT(root);
	printBT(root);
	freeBT(root);

	return 0;
}