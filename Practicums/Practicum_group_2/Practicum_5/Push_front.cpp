#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

void push_back(ListNode*& head, int num) {

	ListNode* newNode = new ListNode(num);
	if (!head) {
		head = newNode;
		return;
	}

	ListNode* curr = head;

	while (curr->next) {
		curr = curr->next;
	}

	curr->next = newNode;
}

void push_front(ListNode*& head, int num) {

	if (!head) {
		push_back(head, num);
	}

	ListNode* newNode = new ListNode(num);

	ListNode* start = newNode;
	start->next = head;
	head = start;
	return;
}
int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	res->next->next = new ListNode{ 3 };
	push_front(res, 4);

	ListNode* printRes = res;
	while (printRes) {
		std::cout << printRes->val << " ";
		printRes = printRes->next;
	}

	ListNode* del = res;
	while (del) {
		ListNode* toDel = del->next;
		delete del;
		del = toDel;
	}

	return 0;
}