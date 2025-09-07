#include<iostream>


//Leetcode: 111
//https://leetcode.com/problems/minimum-depth-of-binary-tree/solutions/
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

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && root->right) {
        return 1 + minDepth(root->right);
    }
    else if (root->left && !root->right) {
        return 1 + minDepth(root->left);
    }
    else {
        return 1 + std::min(minDepth(root->left) , minDepth(root->right));
    }
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
   // root->right->left = new TreeNode(2);

    std::cout << minDepth(root);

    return 0;
}