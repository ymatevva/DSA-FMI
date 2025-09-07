#include<iostream>
//Leetcode: 1379
//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

    if (!original || !cloned) {
        return nullptr;
    }

    if (original == target) {
        return cloned;
    }

    TreeNode* leftAns = getTargetCopy(original->left, cloned->left, target);
    if (leftAns) {
        return leftAns;
    }

    getTargetCopy(original->right, cloned->right, target);

}
int main() {
   
    TreeNode* original = new TreeNode(7);
    original->left = new TreeNode(4);
    original->right = new TreeNode(3);
    original->right->left = new TreeNode(6);
    original->right->right = new TreeNode(19);

   
    TreeNode* cloned = new TreeNode(7);
    cloned->left = new TreeNode(4);
    cloned->right = new TreeNode(3);
    cloned->right->left = new TreeNode(6);
    cloned->right->right = new TreeNode(19);

    
    TreeNode* target = original->right; 

    std::cout << "Original Tree: ";
    printTree(original);
    std::cout << "Cloned Tree: ";
    printTree(cloned);

   
    TreeNode* result = getTargetCopy(original, cloned, target);

    std::cout << result->val;
    
    return 0;
}