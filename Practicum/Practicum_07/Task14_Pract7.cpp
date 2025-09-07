#include<iostream>
#include<vector>
#include<set>

//Leetcode: 653
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
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

//Two ways to solve this task:
//
//void fillValues(TreeNode* root, std::vector<int>& values) {
//    if (!root) {
//        return;
//    }
//
//    fillValues(root->left, values);
//    values.push_back(root->val);
//    fillValues(root->right, values);
//}
//bool findTarget(TreeNode* root, int k) {
//
//    std::vector<int> values;
//    fillValues(root, values);
//
//    int left = 0;
//    int right = values.size() - 1;
//
//    while (left < right) {
//
//        
//        if (values[left] + values[right] == k) {
//            return true;
//        }
//        else if (values[left] + values[right] < k) {
//            left++;
//        }
//        else {
//            right--;
//        }
//    }
//    return false;
//}

//Second with set:

bool isFound(TreeNode* root, int k, std::set<int>& mySet) {

    if (!root) {
        return false;
    }

    if (mySet.count(k - root->val)) {
        return true;
    }

    mySet.insert(root->val);

    return isFound(root->left, k, mySet) || isFound(root->right, k, mySet);

}
bool findTarget(TreeNode* root, int k) {

    std::set<int> mySet;
    return isFound(root, k, mySet);
}


int main() {

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(3);
    std::cout << std::boolalpha << findTarget(root, -2);

}