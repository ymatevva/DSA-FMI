#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct Node {
	Node* left;
	Node* right;
	char data;
	Node(char data, Node* left = nullptr, Node* right = nullptr) :data(data), left(left), right(right) {}
};

struct NodeF {
	char data;
	vector<NodeF*> children;
	NodeF(char data) :data(data) {}
};


//Task 1
bool containsNumF(NodeF* root, int target) {
	if (root->data == target) {
		return true;
	}

	for (size_t i = 0; i < root->children.size(); i++)
	{
		if (containsNumF(root->children[i], target)) {
			return true;
		}
	}
	return false;
}

bool containsNum(Node* root, int target) {
	if (!root) {
		return false;
	}

	return root->data == target || containsNum(root->left, target) || containsNum(root->right, target);
}


//Task2
int getSumElements(Node* root) {
	if (!root) {
		return 0;
	}

	return root->data + getSumElements(root->left) + getSumElements(root->right);
}

int getSumElementsF(NodeF* root) {

	int sum = root->data;
	for (size_t i = 0; i < root->children.size(); i++)
	{
		sum += getSumElementsF(root->children[i]);
	}
	return sum;
}


//Task 3
int max(int a, int b) {
	return a > b ? a : b;
}
int max(int a, int b, int c) {
	return max(max(a, b), c);
}

int getMaxElement(Node* root) {
	if (!root) {
		return INT_MIN;
	}

	if (!root->left && !root->right) {
		return root->data;
	}

	else if (!root->left && root->right) {
		return max(root->data, getMaxElement(root->right));
	}
	else if (root->left && !root->right) {
		return max(root->data, getMaxElement(root->left));
	}

	return max(root->data, max(getMaxElement(root->left), getMaxElement(root->right)));
}


int getMaxElementF(NodeF* root) {

	int maxEl = root->data;

	for (size_t i = 0; i < root->children.size(); i++)
	{
		maxEl = max(getMaxElementF(root->children[i]), maxEl);
	}
	return maxEl;
}

//task 4
int getHeight(Node* root) {
	if (!root) {
		return -1;
	}

	return 1 + max(getHeight(root->right), getHeight(root->left));
}

int getHeightF(NodeF* root) {

	int height = -1;
	for (size_t i = 0; i < root->children.size(); i++)
	{
		height = max(getHeightF(root->children[i]), height);
	}
	return height + 1;
}


//Task 5
int countEl(Node* root) {
	if (!root) {
		return 0;
	}

	return 1 + countEl(root->left) + countEl(root->right);
}

int countElF(NodeF* root) {

	int count = 1;
	for (size_t i = 0; i < root->children.size(); i++)
	{
		count += countElF(root->children[i]);
	}
	return count;
}

//Task 6
bool helpOcc(Node* root, vector<bool>& occ) {
	if (!root) {
		return true;
	}

	if (root->data < 1 || root->data > occ.size()) {
		return false;
	}

	if (occ[root->data - 1]) {
		return false;
	}

	occ[root->data - 1] = true;

	return helpOcc(root->left, occ) && helpOcc(root->right, occ);
}

bool hasOccuredOnce(Node* root) {
	int elRange = countEl(root);
	vector<bool>occ(elRange, false);
	return helpOcc(root, occ);
}


bool hasOccOnceFHelp(NodeF* root, vector<bool>& occ) {
	if (root->data <= 0 || root->data > occ.size()) {
		return false;
	}
	if (occ[root->data - 1]) {
		return false;
	}
	occ[root->data - 1] = true;
	for (int i = 0; i < root->children.size(); i++)
	{
		if (!hasOccOnceFHelp(root->children[i], occ)) { return false; }
	}
	return true;
}

bool hasOccOnceF(NodeF* root) {

	vector<bool>occ(countElF(root), false);
	return hasOccOnceFHelp(root, occ);
}

//Task 7
void getAllWords(Node* root, vector<string>& res, string currWord) {

	if (!root) {
		return;
	}

	if (!root->left && !root->right) {
		res.push_back(currWord + root->data);
	}

	getAllWords(root->left, res, currWord + root->data);
	getAllWords(root->right, res, currWord + root->data);
}

vector<string>getAllWordPaths(Node* root) {
	vector<string>res;
	string currW = "";
	getAllWords(root, res, currW);
	return res;
}

void getAllWordsF(NodeF* root, vector<string>& res, string currWord) {


	if (!root->children.size()) {
		res.push_back(currWord+root->data);
	}

	for (size_t i = 0; i < root->children.size(); i++)
	{
		getAllWordsF(root->children[i], res, currWord+root->data);
	}
}


vector<string>getAllWordPathsF(NodeF* root) {
	vector<string>res;
	string currW = "";
	getAllWordsF(root, res, currW);
	return res;
}

//Task 8
void printWordOnLevelK(Node* root, int k) {

	queue<Node*> myQ;

	myQ.push(root);

	while (!myQ.empty()) {

		k--;
		string currWord = "";

		size_t currLSize = myQ.size();

		for (size_t i = 0; i < currLSize; i++)
		{
			auto topEl = myQ.front();
			myQ.pop();

			currWord += topEl->data;
			if (topEl->left) {
				myQ.push(topEl->left);
			}
			if (topEl->right) {
				myQ.push(topEl->right);
			}
		}
		if (!k) {
			std::cout << currWord << std::endl;
			return;
		}
	}
}


void printWordOnLevelKF(NodeF* root, int k) {

	queue<NodeF*> myQ;

	myQ.push(root);

	while (!myQ.empty()) {

		
		string currWord = "";

		size_t currLSize = myQ.size();

		for (size_t i = 0; i < currLSize; i++)
		{
			auto topEl = myQ.front();
			myQ.pop();

			currWord += topEl->data;
			for (size_t i = 0; i < topEl->children.size(); i++)
			{
				myQ.push(topEl->children[i]);
			}
		}

		if (!k) {
			std::cout << currWord << std::endl;
			return;
		}
		k--;
	}
}

void free(Node* root) {
	if (!root) {
		return;
	}
	free(root->left);
	free(root->right);
	delete root;
}

void freeF(NodeF* root) {

	for (size_t i = 0; i < root->children.size(); i++)
	{
		freeF(root->children[i]);
	}
	delete root;
}


//DFS
void dfsHelp(Node* root, vector<vector<int>>& paths, vector<int> currPath) {

	if (!root) {
		return;
	}

	currPath.push_back(root->data);
	if (!root->left && !root->right) {
		
		paths.push_back(currPath);
	}

	dfsHelp(root->left, paths, currPath);
	dfsHelp(root->right, paths, currPath);
}

void dfsBinary(Node* root,vector<vector<int>>& paths) {
	vector<int>currP;
	dfsHelp(root, paths, currP);
}

//DFS General
void dfsHelpF(NodeF* root, vector<vector<int>>& paths, vector<int> currPath) {

	currPath.push_back(root->data);
	if (!root->children.size()) {
		paths.push_back(currPath);
	}
	for (size_t i = 0; i < root->children.size(); i++)
	{
		dfsHelpF(root->children[i], paths, currPath);
	}
}

void dfsGeneral(NodeF* root, vector<vector<int>>& paths) {
	vector<int>currP;
	dfsHelpF(root, paths, currP);
}

//Task 9 getNumOfLeaves

int numLeaves(Node* root) {
	if (!root) {
		return 0;
	}
	if (!root->left && !root->right) {
		return 1;
	}
	
	return numLeaves(root->left) + numLeaves(root->right);
}

int numLeavesF(NodeF* root) {
	int sum = 0;
	if (!root->children.size()) {
		sum+= 1;
	}

	for (size_t i = 0; i < root->children.size(); i++)
	{
		sum += numLeavesF(root->children[i]);
	}
	return sum;
}

int maxBranchingF(NodeF* root) {
	int maxBr = root->children.size();
	for (size_t i = 0; i < root->children.size(); i++)
	{
		maxBr = max(maxBr,maxBranchingF(root->children[i]));
	}
	return maxBr;
}

int main() {

	Node* root1 = new Node('a');
	root1->left = new Node('b');
	root1->right = new Node('c');
	root1->right->right = new Node('c');
	root1->right->left = new Node('c');
	std::cout << "Contains num binary tree:" << containsNum(root1, 3) << std::endl;
	std::cout << "Sum elements binary tree: " << getSumElements(root1) << std::endl;
	std::cout << "Max el binary tree: " << getMaxElement(root1) << std::endl;
	std::cout << "Binary tree height: " << getHeight(root1) << std::endl;
	std::cout << "Binary tree count el : " << countEl(root1) << std::endl;
	std::cout << "Elements 1-n has occ once binary : " << std::boolalpha << hasOccuredOnce(root1) << std::endl;
	std::cout << "All word paths: binary " << std::endl;
	vector<string> res = getAllWordPaths(root1);
	for (auto& iter : res) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
	std::cout << " Print word on level k: " << std::endl;
	printWordOnLevelK(root1, 2);

	vector<vector<int>>paths;
	dfsBinary(root1, paths);
	for (auto& vec : paths) {
		for (auto& it : vec) {
			std::cout << it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Num leaves binary: " << numLeaves(root1) << std::endl;

	std::cout << std::endl; 
	NodeF* root = new NodeF('a');
	(root->children).push_back(new NodeF('b'));
	(root->children).push_back(new NodeF('c'));
	(root->children).push_back(new NodeF('d'));
	(root->children[0]->children).push_back(new NodeF('e'));
	(root->children[1]->children).push_back(new NodeF('f'));
	(root->children[1]->children[0]->children).push_back(new NodeF('g'));
	(root->children[2]->children).push_back(new NodeF('i'));
	(root->children[2]->children).push_back(new NodeF('j'));

	std::cout << "Contains num general tree:" << containsNumF(root, 12) << std::endl;
	std::cout << "Sum elements general tree: " << getSumElementsF(root) << std::endl;
	std::cout << "Max el general tree: " << getMaxElementF(root) << std::endl;
	std::cout << "General tree height: " << getHeightF(root) << std::endl;
	std::cout << "General tree count el : " << countElF(root) << std::endl;
	std::cout << "Elements 1-n has occ once general : " << std::boolalpha << hasOccOnceF(root) << std::endl;
	std::cout << "All word paths: general " << std::endl;
	vector<string> res1 = getAllWordPathsF(root);
	for (auto& iter : res1) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
	std::cout << " Print word on level k general : " << std::endl;
	printWordOnLevelKF(root, 3);

	
	vector<vector<int>>pathsF;
	dfsGeneral(root, pathsF);
	for (auto& vec : pathsF) {
		for (auto& it : vec) {
			std::cout << it << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Num leaves general: " << numLeavesF(root) << std::endl;
	std:: cout << "Max branching general: " << maxBranchingF(root) << std::endl;
}