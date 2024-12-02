#include<iostream>
#include<vector>
#include<stack>
#include<exception>

template<typename T, typename Comparator = std::less<T>>
class BST {
	struct Node {
		T data;
		Node* left;
		Node* right;
		size_t treeSize = 1;
		Node(const T& data, Node* left = nullptr, Node* right = nullptr) :data(data), left(left), right(right) {}
	};
	Node* root = nullptr;
	size_t count = 0;
	Comparator comp;

	Node* copyRoot(Node* otherRoot);
	Node** findMin(Node** root);
	void moveFrom(BST&& other);
	void free(Node* root);
public:
	BST() = default;
	explicit BST(const Comparator& comp):comp(comp){}
	BST(const BST& other);
	BST& operator=(const BST& other);
	BST(BST&& other)noexcept;
	BST& operator=(BST&& other)noexcept;
	~BST();

	const T& operator[](size_t ind) const;

	bool contains(const T& el)const;
	bool remove(const T& el);
	bool insert(const T& el);

	bool empty() const;
	size_t getSize() const;
};

template<typename T, typename Comparator>
typename  BST<T, Comparator>::Node* BST<T, Comparator>::copyRoot(Node* otherRoot)
{
	if (!root) {
		return nullptr;
	}
	Node* copyN = new Node(otherRoot->data);
	copyN->treeSize = otherRoot->treeSize;
	copyN->left = copyRoot(root->left);
	copyN->right = copyRoot(root->right);
	return copyN;
}

template<typename T, typename Comparator>
typename  BST<T, Comparator>::Node** BST<T, Comparator>::findMin(Node** root)
{
	Node** iter = root;
	while ((*iter)->left) {
		iter = &(*iter)->left;
	}
	return iter;
}

template<typename T, typename Comparator>
inline void BST<T, Comparator>::moveFrom(BST&& other)
{
	moveFrom(std::move(other));
}

template<typename T, typename Comparator>
inline void BST<T, Comparator>::free(Node* root)
{
	if (!root) {
		return;
	}
	free(root->left);
	free(root->right);
	delete root;
}

template<typename T, typename Comparator>
inline BST<T, Comparator>::BST(const BST& other)
{
	copyFrom(other);
}

template<typename T, typename Comparator>
inline  BST<T, Comparator>& BST<T, Comparator>::operator=(const BST& other)
{
	if (this != &other) {
		free();
		root = copy(other.root);
		comp = other.comp;
		count = other.count;
	}
	return *this;
}

template<typename T, typename Comparator>
inline BST<T, Comparator>::BST(BST&& other) noexcept
{
	comp = other.comp;
	root = other.root;
	other.root = nullptr;
	count = other.count;
	other.count = 0;
}

template<typename T, typename Comparator>
inline  BST<T, Comparator>& BST<T, Comparator>::operator=(BST&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T, typename Comparator>
inline BST<T, Comparator>::~BST()
{
	free(root);
}

template<typename T, typename Comparator>
inline const T& BST<T, Comparator>::operator[](size_t ind) const
{
	Node* iter = root;
	int currInd = ind;
	while (iter) {
		size_t leftTreeSize = iter->left ? iter->left->treeSize : 0;
		if (ind < leftTreeSize) {
			iter = iter->left;
		}
		else if (ind > leftTreeSize) {
			ind -= (leftTreeSize + 1);
			iter = iter->right;
		}
		else {
			return iter->data;
		}
	}
	throw std::runtime_error("Inc ind");
}

template<typename T, typename Comparator>
inline bool BST<T, Comparator>::contains(const T& el) const
{
	Node* iter = root;
	while (iter) {
		if (comp(iter->data, el)) {
			iter = iter->right;
		}
		else if (comp(el, iter->data)) {
			iter = iter->left;
		}
		else {
			return true;
		}
	}
	return false;
}

template<typename T, typename Comparator>
inline bool BST<T, Comparator>::remove(const T& el)
{
	Node** iter = &root;
	std::stack<Node*> elements;

	while (*iter) {
		elements.push(*iter);
		if (comp((*iter)->data, el)) {
			iter = &(*iter)->right;
		}
		else if (comp(el, (*iter)->data)) {
			iter = &(*iter)->left;
		}
		else {
			break;
		}
	}
	if (!(*iter)) {
		return false;
	}

	Node* toDel = *iter;

	if (!(*iter)->left && !(*iter)->right) {
		*iter = nullptr;
	}
	else if (!(*iter)->left) {
		*iter = (*iter)->right;
	}
	else if (!(*iter)->right) {
		*iter = (*iter)->left;
	}
	else {
		size_t oldTreeSize = (*iter)->treeSize;
		Node** rightMin = findMin(&(*iter)->right);

		Node* tmp = (*iter)->right;
		while (tmp && tmp != *rightMin) {
			elements.push(tmp);
			tmp = tmp->left;
		}
		*iter = *rightMin;
		*rightMin = (*rightMin)->right;
		(*iter)->treeSize = oldTreeSize - 1;
		(*iter)->left = toDel->left;
		(*iter)->right = toDel->right;
	}

	delete toDel;
	count--;

	while (!elements.empty()) {
		Node* curr = elements.top();
		elements.pop();
		curr->treeSize--;
	}
	return true;
}

template<typename T, typename Comparator>
inline bool BST<T, Comparator>::insert(const T& el)
{
	Node** iter = &root;
	std::stack<Node*> elements;

	while (*iter) {
		elements.push(*iter);
		if (comp((*iter)->data, el)) {
			iter = &(*iter)->right;
		}
		else if (comp(el, (*iter)->data)) {
			iter = &(*iter)->left;
		}
		else {
			return false;
		}
	}
	*iter = new Node(el);
	count++;

	while (!elements.empty()) {
		Node* curr = elements.top();
		elements.pop();
		curr->treeSize++;
	}
	return true;
}

template<typename T, typename Comparator>
inline bool BST<T, Comparator>::empty() const
{
	return count == 0;
}

template<typename T, typename Comparator>
inline size_t BST<T, Comparator>::getSize() const
{
	return count;
}

void treeSort(std::vector<int>& vec) {
	
	BST<int> bT;
	for (size_t i = 0; i < vec.size(); i++)
	{
		bT.insert(vec[i]);
	}
	
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = bT[i];
	}
}