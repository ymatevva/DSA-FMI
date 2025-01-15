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
        
        queue<TreeNode*> myQ;
        myQ.push(root);
        size_t level = 1;

        while (!myQ.empty()) {
            size_t currLSize = myQ.size();
            vector<int> cLevel;

            for (size_t i = 0; i < currLSize; i++) {
                TreeNode* topEl = myQ.front();
                myQ.pop();

                cLevel.push_back(topEl->val);
                
                if (topEl->left) {
                    myQ.push(topEl->left);
                }

                if (topEl->right) {
                    myQ.push(topEl->right);
                }
            }

        
            if (level % 2 == 0) {
                reverse(cLevel.begin(), cLevel.end());
            }

            res.push_back(cLevel);
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
