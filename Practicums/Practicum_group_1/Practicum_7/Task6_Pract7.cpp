#include<iostream>

//Leetcode: 700
//https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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

//It is BTS!!!
TreeNode* searchBST(TreeNode* root, int val) {

    if (!root) {
        return nullptr;
    }

    if (root->val == val) {
        return root;
    }
    else if (root->val < val) {
        searchBST(root->right, val);
    }
    else {
        searchBST(root->left, val);
    }

}

int main() {

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    TreeNode* res = searchBST(root,3);
    print(res);
    free(root);

    return 0;
}
