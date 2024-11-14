#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


template <typename T>
struct NodeFull
{
	T data;
	vector<NodeFull<T>*> children;

	NodeFull(T data) : data(data) {}
};


template<typename T>
void print(NodeFull<T>* root) {

	std::cout << root->data << " ";
	for (size_t i = 0; i < root->children.size(); i++)
	{
		print(root->children[i]);
	}
}

template<typename T>
void free(NodeFull<T>* root) {
	for (size_t i = 0; i < root->children.size(); i++)
	{
		free(root->children[i]);
	}
	delete root;
}

//Task1 : contains
//
//template<typename T>
//bool contains(int num, NodeFull<T>* root) {
//
//	if (root->data == num){
//		return true;
//	}
//	for (size_t i = 0; i < root->children.size(); i++)
//	{
//		if (contains(num, root->children[i])) {
//			return true;
//		}
//	}
//	return false;
//}

//
////Task 2 Sum elements
//template<typename T>
//int sumElements(NodeFull<T>* root) {
//
//	int sum = root->data;
//
//	for (size_t i = 0; i < root->children.size(); i++)
//	{
//		sum += sumElements(root->children[i]);
//	}
//	return sum;
//}

//task3;
//template<typename T>
//int getMaxEl(NodeFull<T>* root) {
//
//	int maxEl = root->data;
//	for (size_t i = 0; i < root->children.size(); i++)
//	{
//		int curr = getMaxEl(root->children[i]);
//		if (curr > maxEl) {
//			maxEl = curr;
//		}
//	}
//	return maxEl;
//}

//task4 getHeight
//
//template<typename T>
//int getHeight(NodeFull<T>* root) {
//
//	if (!root) {
//		return 0;
//	}
//	int maxHeight = 0;
//	for (size_t i = 0; i < root->children.size(); i++)
//	{
//		int childHeight = getHeight(root->children[i]);
//		if (childHeight > maxHeight) {
//			maxHeight = childHeight;
//		}
//	}
//	return maxHeight+1;
//}


template<typename T>
int getCountElements(NodeFull<T>* root) {

	if (!root) {
		return 0;
	}
	int sum = 0;

	for (size_t i = 0; i < root->children.size(); i++)
	{
		sum += getCountElements(root->children[i]);
	}
	return sum + 1;
}

////Task 6 Word on level
//template<typename T>
//string wordOnLevel(NodeFull<T>* root, int level) {
//
//	string res;
//	if (!root) {
//		return "";
//	}
//	if (level == 1) {
//		return  res + (char)root->data;
//	}
//	for (size_t i = 0; i < root->children.size(); i++)
//	{
//		res += wordOnLevel(root->children[i], level - 1);
//	}return res;
//
//}

//Task nz koq
//template<typename T>
//int countLeaves(NodeFull<T>* root) {
//
//	int sum = 0;
//	if (root->children.size() == 0) {
//		return 1;
//	}
//    for (size_t i = 0; i < root->children.size(); i++)
//	{
//		sum += countLeaves(root->children[i]);
//	}
//	return sum;
//}

//Task 1-n numbers

//bool markOccured(NodeFull<int>* root, vector<int>& occurences, size_t elementsCount) {
//	if (root->data < 1 || root->data > elementsCount) {
//		return false;
//	}
//	if (occurences[root->data - 1]) {
//		return false;
//	}
//	occurences[root->data-1] = true;
//	for (size_t i = 0; i < root->children.size(); i++)
//	{
//		if (!markOccured(root->children[i], occurences, elementsCount)) {
//			return false;
//		}
//	}
//	return true;
//}
//bool areAllNumbersInTree(NodeFull<int>* root) {
//
//	size_t elementsCount = getCountElements<int>(root);
//	vector<int>occurences(elementsCount, 0);
//	return markOccured(root, occurences,elementsCount);
//
//}

void fillWords(NodeFull<char>* root, vector<string>& words, string word) {


	word += (char)(root->data);

	if (!root->children.size()) {
		words.push_back(word);
		return;
	}

	for (size_t i = 0; i < root->children.size(); i++)
	{
		fillWords(root->children[i], words, word);
	}
	;
}
//Task will words from root to leaf
void  getWords(NodeFull<char>* root,vector<string>& words) {
	fillWords(root, words, "");
	return;
}
int main() {

	//NodeFull<int>* root = new NodeFull<int>(1);

	//(root->children).push_back(new NodeFull<int>(2));
	//(root->children).push_back(new NodeFull<int>(3));
	//(root->children).push_back(new NodeFull<int>(4));
	//(root->children[0]->children).push_back(new NodeFull<int>(5));
	//(root->children[1]->children).push_back(new NodeFull<int>(6));
	//(root->children[1]->children[0]->children).push_back(new NodeFull<int>(7));
	//(root->children[2]->children).push_back(new NodeFull<int>(8));
	//(root->children[2]->children).push_back(new NodeFull<int>(9));

	////std::cout << contains(6, root);
	//std::cout << sumElements(root);
	//std::cout << getMaxEl(root);
	//std::cout << getHeight(root);
	//std::cout << getCountElements(root);
	//std::cout << countLeaves(root);
	//std::cout << areAllNumbersInTree(root);


	NodeFull<char>* root = new NodeFull<char>('A');

	(root->children).push_back(new NodeFull<char>('B'));
	(root->children).push_back(new NodeFull<char>('C'));
	(root->children).push_back(new NodeFull<char>('D'));
	(root->children[0]->children).push_back(new NodeFull<char>('E'));
	(root->children[1]->children).push_back(new NodeFull<char>('F'));
	(root->children[1]->children[0]->children).push_back(new NodeFull<char>('G'));
	(root->children[2]->children).push_back(new NodeFull<char>('H'));
	(root->children[2]->children).push_back(new NodeFull<char>('I'));
	vector<string>words;
	getWords(root, words);
	for (size_t i = 0; i < words.size(); i++)
	{
		std::cout << words[i] << " ";
	}
}