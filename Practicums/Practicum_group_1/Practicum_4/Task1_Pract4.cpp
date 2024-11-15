#include<iostream>
using namespace std;

//reverse linked list 

struct Node {
	int val;
	Node* next;
	Node(int val):val(val),next(nullptr){}
};


Node* reverse(Node* head) {
	if (!head || !head->next) {
		return head;
	}

	Node* curr = head;
	Node* prev = nullptr;
	while (curr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = curr->next;
	}
	return prev;
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
int main() {

	Node* test = new Node(1);
	test->next = new Node(2);
	test->next->next = new Node(3);
	test->next->next->next = new Node(4);
	print(reverse(test));

	return 0;
}