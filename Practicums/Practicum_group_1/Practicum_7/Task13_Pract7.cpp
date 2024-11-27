#include<iostream>
#include<vector>

//Leetcode: 108
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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

TreeNode* createBST(std::vector<int>& vec, int left, int right) {

    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;

    TreeNode* root = new TreeNode(vec[mid]);
    root->left = createBST(vec, left, mid - 1);
    root->right = createBST(vec, mid+1, right);
    return root;
}


TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return createBST(nums, 0, nums.size() - 1);
}
int main() {

    std::vector<int> vec = { -10,-3,0,5,9 };
    TreeNode* created = sortedArrayToBST(vec);
    print(created);
    free(created);
}