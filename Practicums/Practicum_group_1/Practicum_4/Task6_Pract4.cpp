#include<iostream>
using namespace std;

//leetcode.com/problems/remove-duplicates-from-sorted-list/description/?envType=problem-list-v2&envId=anqpylct
struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

void removeDuplicates(Node* head) {
	if (!head || !head->next) {
		return;
	}

	Node* iter = head;
	while (iter && iter->next) {
		if (iter->val == iter->next->val) {
			iter->next = iter->next->next;
		}else{
		iter = iter->next;
		}
			
	}
}

void print(Node* head) {
	if (!head) {
		return;
	}
	Node* iter = head;
	while (iter) {
		std::cout << iter->val << " ";
		iter = iter->next;
	}

}

void free(Node* head) {
	if (!head) {
		return;
	}
	Node* iter = head;
	while (iter) {
		Node* toDel = iter;
		iter = iter->next;
		delete toDel;
	}
}
int main() {

	Node* test = new Node(1);
	test->next = new Node(2);
	test->next->next = new Node(2);
	test->next->next->next = new Node(3);
	removeDuplicates(test);
	print(test);
	return 0;
}
