#include<iostream>
#include<stack>
using namespace std;


template<class T, typename Comparator = std::less<T>>
class BST {

	struct Node {
		T data;
		Node* left;
		Node* right;
		size_t treeSize = 1;
		Node(const T& data, Node* left = nullptr, Node* right = nullptr) {}
	};

	Node* root = nullptr;
	size_t size = 0;
	Comparator comp;

	Node* copy(Node* root);
	void free(Node* root);
	Node** findMinNode(Node** root);
	const Node& getNodeAtInd(const Node& node, size_t ind) const;
public:
	BST() = default;
	BST(const BST& other);
	BST& operator=(const BST& other);
	~BST();

	const T& operator[](size_t ind) const;

	bool insert(const T& data);
	bool remove(const T& data);
	bool conatins(const T& data) const;
};

template<class T, typename Comparator>
BST<T, Comparator>::Node* BST<T, Comparator>::copy(Node* root)
{
	if (!root) {
		return nullptr;
	}

	Node* res = new Node(root->data);
	res->left = copy(root->left);
	res->right = copy(root->right);
	return res;
}

template<class T, typename Comparator>
void BST<T, Comparator>::free(Node* root)
{
	if (!root) {
		return;
	}

	free(root->left);
	free(root->right);
	delete root;
}

template<class T, typename Comparator>
BST<T, Comparator>::Node** BST<T, Comparator>::findMinNode(Node** root)
{
	Node** iter = &root;
	while ((*iter)->left) {
		iter = &(*iter)->left;//we move to the left searvinh for the smallest node;
	}
	return iter;
}

template<class T, typename Comparator>
const BST<T, Comparator>::Node& BST<T, Comparator>::getNodeAtInd(const Node& node, size_t ind) const
{
	size_t currTreeSize = node.treeSize;
	if (currTreeSize == ind) {
		return node;
	}if (currTreeSize > ind) {
		return getNodeAtInd(*node.left, ind);
	}
	else {
		return getNodeAtInd(*node.right, ind - treeSize - 1);
	}
}

template<class T, typename Comparator>
BST<T, Comparator>::BST(const BST& other)
{
	root = copy(other.root);
	size = other.size;
}

template<class T, typename Comparator>
BST<T, Comparator>& BST<T, Comparator>::operator=(const BST& other)
{
	if (this != &other) {
		free(root);
		root = copy(other.root);
		size = other.size;
		comp = other.comp;
	}
	return *this;
}

template<class T, typename Comparator>
BST<T, Comparator>::~BST()
{
	free();
}

template<class T, typename Comparator>
const T& BST<T, Comparator>::operator[](size_t ind) const
{
	return getNodeAtInd(*root, ind).data;
}

template<class T, typename Comparator>
bool BST<T, Comparator>::insert(const T& data)
{
	Node** iter = &root;

	while (*iter) {
		(*iter)->treeSize++;
		if (comp(data, (*iter)->data)) {
			iter = &(*iter)->left;
		}
		else if (comp((*iter)->data, data)) {
			iter = &(*iter)->right;
		}
		else {
			break;
		}
	}
	if (!(*iter)) {
		return false;
	}

	*iter = new Node(data);
	size++;
	return true;

}

template<class T, typename Comparator>
bool BST<T, Comparator>::remove(const T& data)
{
	Node** iter = &root;
	stack<Node**>mySt;

	while (*iter) {
		mySt.push(iter);
		if (comp(data, (*iter)->data)) {
			iter = &(*iter)->left;
		}
		else if (comp((*iter)->data, data)) {
			iter = &(*iter)->right;
		}
		else {
			break;
		}
	}

	if (!(*iter)) {
		return false;//we have not found the element to be removed
	}

	Node* del = *iter;
	if (!(*iter)->left && !(*iter)->right) {
		*iter = nullptr;
	}
	else if (!(*iter)->left) {
		*iter = (*iter)->right;
	}
	else if (!(*iter)->right) {
		*iter = (*iter)->left;
	}
	else {//this is the most complex case where there are both left and right child
		//first we search for the leftest in the right child bc this is the first el bigger than the one we want to dleete 
		Node** minNodeToTheRight = findMinNode(&(*iter)->right);

		*iter = *minNodeToTheRight;

		*minNodeToTheRight = (*minNodeToTheRight)->right;

		(*iter)->left = del->left;
		(*iter)->right = del->right;
	}

	delete del;

	while (!mySt.empty()) {
		Node* topEl = *mySt.top();
		mySt.pop();
		topEl->treeSize = topEl->left->treeSize + topEl->right->treeSize + 1;
	}
	size--;
	return true;
}

template<class T, typename Comparator>
bool BST<T, Comparator>::conatins(const T& data) const
{
	Node* iter = root;
	while (iter) {
		if (comp(data, iter->data)) {
			iter = iter->left;
		}
		else if (comp(iter->data, data)) {
			iter = iter->right;
		}
		else {
			return true;
		}
	}
	return false;
}
