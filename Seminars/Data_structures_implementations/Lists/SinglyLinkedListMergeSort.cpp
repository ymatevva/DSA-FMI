#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val, Node* next = nullptr) :val(val), next(next) {}
};

void pushBack(Node*& beg, Node*& end, Node* add) {
	if (!beg) {
		beg = end = add;
	}
	else {
		end->next = add;
		end = add;
	}
}

Node* merge(Node* first, Node* sec) {
	Node* beg = nullptr;
	Node* end = nullptr;

	while (first && sec) {

		if (first->val < sec->val) {
			pushBack(beg, end, first);
			first = first->next;
		}
		else {
			pushBack(beg, end, sec);
			sec = sec->next;
		}
	}

	if (!first) {
		pushBack(beg, end, sec);
	}
	if (!sec) {
		pushBack(beg, end, first);
	}
	return beg;
}

Node* split(Node* head) {
	Node* fast = head->next;
	Node* slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeSort(Node* head) {
	if (!head || !head->next) {
		return head;
	}


	Node* mid = split(head);
	Node* left = head;
	Node* right = mid->next;
	mid->next = nullptr;

	Node* sortedL = mergeSort(left);
	Node* sortedR = mergeSort(right);
	merge(sortedL, sortedR);
}



void print(const Node* root)
{
	while (root)
	{
		std::cout << root->val << " ";
		root = root->next;
	}
	std::cout << std::endl;
}

void freeList(Node* root)
{
	Node* current = root;
	while (current)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}
int main()
{
	Node* list = new Node(20, new Node(14, new Node(7)));
	list = mergeSort(list);
	print(list);
	freeList(list);
	list = nullptr;
}
