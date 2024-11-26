#include<iostream>


//Leetcode: 222
//https://leetcode.com/problems/count-complete-tree-nodes/description/
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

int getRightHeight(TreeNode* root) {

    int height = 0;
    while (root) {
        height++;
        root = root->right;
    }
    return height;
}
int getLeftHeight(TreeNode* root) {

    int height = 0;
    while (root) {
        height++;
        root = root->left;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftH = getLeftHeight(root);
    int rightH = getRightHeight(root);

    if (leftH == rightH) {
        return (1 << leftH) - 1;//formula for perfect bt
    }
    else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left ->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(2);

    std::cout << countNodes(root);
    return 0;
}