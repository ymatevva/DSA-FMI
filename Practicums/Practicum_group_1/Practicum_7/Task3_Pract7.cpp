#include<iostream>

//Leetcode 938:
//https://leetcode.com/problems/range-sum-of-bst/

struct TNode {
	int val;
	TNode* left;
	TNode* right;
	TNode(int val) :val(val), left(nullptr), right(nullptr) {}
};


void print(TNode* root) {
	if (!root) {
		return;
	}

	std::cout << root->val << " ";
	print(root->left);
	print(root->right);
}

void free(TNode* root) {
	if (!root) {
		return;
	}

	free(root->left);
	free(root->right);
	delete root;
}

//This is not efficient if the tree is bst
//void sumInRange(TNode* root, int low, int high, int& sum) {
//
//	if (!root) {
//		return;
//	}
//
//	if (root->val >= low && root->val <= high) {
//		sum += root->val;
//	}
//
//	sumInRange(root->left,low,high,sum);
//	sumInRange(root->right,low,high,sum);
//}

void sumInRange(TNode* root, int low, int high, int& sum) {
	if (!root) {
		return;
	}

	if (root->val < low) {
		return sumInRange(root->right, low, high, sum);
	}
	else if (root->val > high) {
		return sumInRange(root->left, low, high, sum);
	}
	else {
		sum += root->val;
	}

	sumInRange(root->left, low, high, sum);
	sumInRange(root->right, low, high, sum);
}
int rangeSumBST(TNode* root, int low, int high) {

	int sum = 0;
	sumInRange(root, low, high, sum);
	return sum;
}


int main() {
	TNode* root = new TNode(10);
	root->left = new TNode(5);
	root->left->left = new TNode(3);
	root->left->right = new TNode(7);
	root->right = new TNode(15);
	root->right->right = new TNode(18);

	print(root);
	std::cout << "Sum in range: " << rangeSumBST(root,7,15) << std::endl;
	free(root);
}
