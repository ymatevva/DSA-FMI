#include<iostream>

//Leetcode: 2331
//https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

void freeTree(TreeNode* root) {
    if (!root) return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
bool evaluateTree(TreeNode* root) {
    
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return root->val;//it is a leaf
    }
    else {
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }

}

int main() {
   
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

   
  
    bool result = evaluateTree(root);
    std::cout << std::boolalpha << result << std::endl;

    freeTree(root);

    return 0;
}
