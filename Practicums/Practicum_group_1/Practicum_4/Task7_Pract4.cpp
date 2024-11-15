#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
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
		curr = next;
	}
	return prev;
}
Node* sumOfTwo(Node* first, Node* second) {
	if (!first || !second) {
		return nullptr;
	}

	Node* iter1 = reverse(first);
	Node* iter2 = reverse(second);
	Node* res = nullptr;

	int helpVar = 0;

	while (iter1 || iter2||helpVar) {
		int sum = helpVar;
		if (iter1) {
			sum += iter1->val;
			iter1 = iter1->next;
		} 
		if (iter2) {
			sum += iter2->val;
			iter2 = iter2->next;
		}
		helpVar = sum / 10;
		Node* newNode = new Node(sum % 10);
		newNode->next = res;
		res = newNode;
	}
	return res;
}
int main() {

	Node* test = new Node(1);
	test->next = new Node(2);
	test->next->next = new Node(2);
	test->next->next->next = new Node(3);
	
	Node* test1 = new Node(1);
	test1->next = new Node(8);
	test1->next->next = new Node(2);
	test1->next->next->next = new Node(1);

	Node* result = sumOfTwo(test, test1);
	while (result) {
		std::cout << result->val << " ";
		result = result->next;
	}
	return 0;
}