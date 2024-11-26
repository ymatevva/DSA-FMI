#include<iostream>


//Leetcode: 104
//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void print(TreeNode* root) {
    if (!root) {
        return;
    }

    print(root->left);
    std::cout << root->val << " ";
    print(root->right);
}

void free(TreeNode* root) {
    if (!root) return;

    free(root->left);
    free(root->right);
    delete root;
}

int maxDepth(TreeNode* root) {

    if (!root) {
        return 0;
    }
   
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main() {
	

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(8);

    std::cout << maxDepth(root) << std::endl;
	return 0;
}