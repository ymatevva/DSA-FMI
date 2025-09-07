#include<iostream>
#include<cstring>
#include<vector>
#include<string>

//Leetcode 257:
//https://leetcode.com/problems/binary-tree-paths/?envType=problem-list-v2&envId=awtrxc3t

struct TNode{
	int val;
	TNode* left;
	TNode* right;
	TNode(int val):val(val),left(nullptr),right(nullptr){}
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

void fillPaths(TNode* root, std::vector<std::string>& paths, std::string str) {

	if (!root) {
		return;
	}
	if (!root->left && !root->right) {
		str += std::to_string(root->val);
		paths.push_back(str);
		return;
	}

	str += std::to_string(root->val) + "->";
	fillPaths(root->left, paths, str);
	fillPaths(root->right, paths, str);
	return;
}

std::vector<std::string>returnAllPaths(TNode* root) {
	if (!root) {
		return std::vector<std::string>();
	}

	std::vector<std::string>paths;
	fillPaths(root, paths, "");
	return paths;
}

void printStr(const std::vector<std::string>& vecString) {
	for (size_t i = 0; i < vecString.size(); i++)
	{
		std::cout << vecString[i] << " ";
	}
}
int main() {
	TNode* root = new TNode(1);
	root->left = new TNode(2);
	root->left->left = new TNode(5);
	root->right = new TNode(3);

	print(root);
	std::vector<std::string> res = returnAllPaths(root);
	free(root);
	printStr(res);
	return 0;
}