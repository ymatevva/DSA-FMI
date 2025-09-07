#include<iostream>


//Leetcode: 872
//https://leetcode.com/problems/leaf-similar-trees/

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

void fillLeaves(TreeNode* root, vector<int>& leaves) {

    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        leaves.push_back(root->val);
    }

    fillLeaves(root->left, leaves);
    fillLeaves(root->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int>leaves1;
    vector<int>leaves2;

    fillLeaves(root1, leaves1);
    fillLeaves(root2, leaves2);

    if (leaves1.size() != leaves2.size()) {
        return false;
    }
    for (int i = 0; i < leaves1.size(); i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    //tested in leetcode
    return 0;
}