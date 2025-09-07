#include<iostream>
using namespace std;

//middle of linked list

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

Node* split(Node* head) {
	if (!head || !head->next) {
		return head;
	}

	Node* fast = head;
	Node* slow = head;

	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main() {

	Node* test = new Node(1);
	test->next = new Node(2);
	test->next->next = new Node(3);
	test->next->next->next = new Node(4);

	Node* mid = split(test);
	std::cout << mid->val;
	return 0;
}
