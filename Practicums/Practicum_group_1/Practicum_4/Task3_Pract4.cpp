#include<iostream>
using namespace std;

//cycle detetection

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

bool isCycle(Node* head) {
	if (!head || !head->next) {
		return head;
	}

	Node* fast = head;
	Node* slow = head;

	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

int main() {

	Node* test = new Node(1);
	test->next = new Node(2);
	test->next->next = new Node(3);
	test->next->next->next = test->next;

	std::cout << isCycle(test);
	return 0;
}
