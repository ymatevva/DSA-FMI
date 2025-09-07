#include<iostream>


//Leetcode: 112
//https://leetcode.com/problems/path-sum/

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




bool isTargetFound(TreeNode* root, int targetSum, int sum) {

    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {

        sum += root->val;
        if (sum == targetSum) {
            return true;
        }
        else {
            return false;
        }
    }

    return isTargetFound(root->left, targetSum, sum + root->val) || isTargetFound(root->right, targetSum, sum + root->val);

}
bool hasPathSum(TreeNode* root, int targetSum) {

    if (!root) {
        return false;
    }
    return isTargetFound(root, targetSum, 0);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(2);

    std::cout << hasPathSum(root,27);
}
return 0;