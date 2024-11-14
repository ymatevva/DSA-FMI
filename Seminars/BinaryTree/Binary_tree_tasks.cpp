#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val):val(val),left(nullptr),right(nullptr){}
};


//Task 1:contains

//bool contains(Node* root,int num) {
//	if (!root) {
//		return false;
//	}
//
//	return root->val == num || contains(root->left, num) || contains(root->right, num);
//}


//task2: sumElements
//
//int sumElements(Node* root) {
//	if (!root) {
//		return 0;
//	}
//	return root->val + sumElements(root->left) + sumElements(root->right);
//}


//Task3:get Height

//int getHeight(Node* root) {
//
//	if (!root) {
//		return 0;
//	}
//
//	return 1 + max(getHeight(root->left), getHeight(root->right));
//}

//
//int max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int max(int a, int b, int c) {
//	return max(a,(max(b, c)));
//}
//task4:
//int getMaxElement(Node* root) {
//
//	if (root->left == nullptr && root->right == nullptr) {
//		return root->val;
//	}
//	else if (root->left == nullptr && root->right != nullptr) {
//		return max(root->val, getMaxElement(root->right));
//	}
//	else if (root->left != nullptr && root->right == nullptr) {
//		return max(root->val, getMaxElement(root->left));
//	}
//	return max(root->val, getMaxElement(root->left), getMaxElement(root->right));
//}

//Task 5:countElements
//int countElements(Node* root) {
//	if (!root) {
//		return 0;
//	}
//
//	return 1 + countElements(root->left) + countElements(root->right);
//}

//Task7
//string getStrOnLevel(Node* root, int level) {
//	if (!root) {
//		return "";
//	}
//	if(level==0) {
//		string res;
//		res += (char)root->val;
//		return res;
//	}
//	return getStrOnLevel(root->left, level - 1) + getStrOnLevel(root->right, level - 1);
//}

//Task8

void fillWords(Node* root, vector<string>& vec, string str) {
	if (!root) {
		return;
	}
	if (root->left == nullptr && root->right == nullptr) {
		vec.push_back(str + (char)(root->val));
	}
	fillWords(root->left, vec, str+(char)(root->val));
	fillWords(root->right, vec, str+(char)(root->val));
}

vector<string> getWords(Node* root)
{
	vector<string> result;
	fillWords(root, result, "");
	return result;
}

int main() {

	//Node* root = new Node(1);     //   1
	//Node* n1 = new Node(2);      //  / \
 //                                //  2   5
	//Node* n3 = new Node(4);     //  / \
 //                               // 3   4

	//Node* n2 = new Node(3);
	//Node* n4 = new Node(5);
	//Node* n5 = new Node(6);


	//root->left = n1;
	//root->right = n4;
	//n1->left = n2;
	//n1->right = n3;
	//n2 -> left = n5;

	Node* root = new Node('A');
	Node* n1 = new Node('B');
	Node* n2 = new Node('C');
	Node* n3 = new Node('D');
	Node* n4 = new Node('E');
	Node* n5 = new Node('F');
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n2->left = n4;
	n2->right = n5;

	//Test1:
	//std::cout << contains(root, 6);

	//Test2:
	//std::cout << sumElements(root);


	//Test3
	//std::cout << getHeight(root);


	//Task 4
	//std::cout << getMaxElement(root);
	// 
	// 
	//Test 5:
	//std::cout << countElements(root);

	//Task 7
	std::cout << getStrOnLevel(root, 1);
	return 0;
}