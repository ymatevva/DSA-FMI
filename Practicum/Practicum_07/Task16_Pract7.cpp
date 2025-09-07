#include <iostream>
#include <vector>
using namespace std;

//Task 897
//https://leetcode.com/problems/increasing-order-search-tree/?envType=problem-list-v2&envId=aw7610t5

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


    void getNums(TreeNode* root, vector<int>& nums) {
        if (!root) {
            return;
        }
        getNums(root->left, nums);
        nums.push_back(root->val);
        getNums(root->right, nums);
    }

    TreeNode* makeNewTree(vector<int> nums, int ind) {
        if (ind == nums.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(nums[ind]);
        root->right = makeNewTree(nums, ind + 1);
        return root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (!root || !root->left) {
            return root;
        }
        vector<int> nums;
        getNums(root, nums);
        return makeNewTree(nums, 0);
    }


void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

  
    TreeNode* newRoot = increasingBST(root);
    printInOrder(newRoot); 
    return 0;
}
