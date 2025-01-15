// Task: Convert BST to Greater Tree
// LeetCode Task Number: 1038
// Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

size_t getTreeSize(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return getTreeSize(root->left) + getTreeSize(root->right) + 1;
}

void getOccurrences(vector<bool>& visited, TreeNode* root) {
    if (!root) {
        return;
    }
    visited[root->val] = true;
    getOccurrences(visited, root->left);
    getOccurrences(visited, root->right);
}

int genSum(const vector<bool>& occ, int val) {
    int sum = 0;
    for (int i = 0; i < occ.size(); i++) {
        if (occ[i] && i >= val) {
            sum += i;
        }
    }
    return sum;
}

void getGreaterTree(TreeNode* root, const vector<bool>& visited) {
    if (!root) {
        return;
    }
    root->val = genSum(visited, root->val);
    getGreaterTree(root->left, visited);
    getGreaterTree(root->right, visited);
}

TreeNode* bstToGst(TreeNode* root) {
    size_t treeSize = getTreeSize(root);
    vector<bool> visited(100, false);
    getOccurrences(visited, root);
    getGreaterTree(root, visited);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2, nullptr, new TreeNode(3));
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7, nullptr, new TreeNode(8));

    root = bstToGst(root);


    freeTree(root);
    return 0;
}
