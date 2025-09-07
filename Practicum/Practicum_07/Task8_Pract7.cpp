#include<iostream>


//Leetcode: 404
//https://leetcode.com/problems/sum-of-left-leaves/description/

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

void getSum(TreeNode* root, int& sum) {
    if (!root) {
       return ;
    }


    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    }

    getSum(root->left,sum);
    getSum(root->right,sum);
}

int sumOfLeftLeaves(TreeNode* root) {

    int sum = 0;
    getSum(root, sum);
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    //root->right->right->right = new TreeNode(8);

    std::cout << sumOfLeftLeaves(root);
}
