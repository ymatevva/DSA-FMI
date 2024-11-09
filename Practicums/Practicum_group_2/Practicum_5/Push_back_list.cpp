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

int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
    res->next->next = new ListNode{ 3 };
	push_back(res, 4);

	ListNode* res2 = nullptr;
	push_back(res2, 4);
	ListNode* printRes = res2;
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