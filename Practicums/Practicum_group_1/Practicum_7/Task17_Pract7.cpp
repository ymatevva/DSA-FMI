#include<iostream>
#include<vector>
using namespace std;


//Task 103
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=problem-list-v2&envId=aw7610t5


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (!root) {
		return res;
	}

	queue<TreeNode*> nodes;
	nodes.push(root);
	int level = 1;
	while (!nodes.empty()) {
		
		vector<int> currLevel;
		size_t currLSize = nodes.size();

		for (size_t i = 0; i < currLSize; i++) {
			
			TreeNode* topEl = nodes.front();
			nodes.pop();

			if (level % 2 == 1) {
				currLevel.push_back(topEl->val);
			}
			else {
				currLevel.insert(currLevel.begin(), topEl->val);
			}

			if (topEl->left) {
				nodes.push(topEl->left);
			}
			if (topEl->right) {
				nodes.push(topEl->right);
			}
		}

		res.push_back(currLevel);
		level++; 
	}

	return res;
}

int main() {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
  
	vector<vector<int>> result = zigzagLevelOrder(root);
	for (const auto& level : result) {
		for (int val : level) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;

}
