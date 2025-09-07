#include<iostream>
#include<queue>

//Leetcode: 1302
//https://leetcode.com/problems/deepest-leaves-sum/description/


struct TNode {
	int val;
	TNode* left;
	TNode* right;
	TNode(int val) : val(val), left(nullptr) , right(nullptr){}
};
void free(TNode* root) {
	if (!root) {
		return;
	}

	free(root->left);
	free(root->right);
	delete root;
}

void print(TNode* root) {

	if (!root) {
		return;
	}
	std::cout << root->val << " ";
	print(root->left);
	print(root->right);
}

//DFS solving;
//
//int getMaxDepth(TNode* root) {
//	if (!root) {
//		return 0;
//	}
//
//	return std::max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
//}
//
//void accumulateSum(TNode* root,int currLevel,int maxLevel, int& sum) {
//
//	if (!root) {
//		return;
//	}
//
//	if ( currLevel == maxLevel) {
//		sum += root->val;
//		return;
//	}
//	accumulateSum(root->left, currLevel+1, maxLevel, sum);
//	accumulateSum(root->right, currLevel+1, maxLevel, sum);
//
//}
//int getSumDeepestLeaves(TNode* root) {
//
//	int sum = 0;
//	if (!root) {
//		return sum;
//	}
//	size_t maxDepth = getMaxDepth(root);
//	accumulateSum(root,1,maxDepth, sum);
//	return sum;
//}

//BFS solving:
int getSumDeepestLeaves(TNode* root) {

	std::queue<TNode*> myQ;
	myQ.push(root);
	size_t currSum = myQ.front()->val;

	while (!myQ.empty()) {

		size_t currLevelSize = myQ.size();
		currSum = 0;
		for (size_t i = 0; i < currLevelSize; i++)
		{
			currSum += myQ.front()->val;
			if(myQ.front()->left)
			myQ.push(myQ.front()->left);
			if (myQ.front()->right)
			myQ.push(myQ.front()->right);
			myQ.pop();
		}
	}
	return currSum;
}

int main() {

	TNode* root = new TNode(1);
	root->left = new TNode(2);
	root->right = new TNode(3);
	root->left->left = new TNode(4);
	root->left->left->left = new TNode(7);
	root->left->right = new TNode(5);
	root->right->right = new TNode(6);
	root->right->right->right = new TNode(8);

	//std::cout << getMaxDepth(root) << " ";
	std::cout << getSumDeepestLeaves(root);
	return 0;
}