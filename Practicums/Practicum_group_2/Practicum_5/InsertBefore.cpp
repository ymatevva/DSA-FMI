#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

void insertBefore(ListNode* head, ListNode* insertBefore, int num) {

	if (!head || !insertBefore) {
		return;
	}

	ListNode* newNode = new ListNode(num);
	ListNode* curr = head;
	while (curr->next && curr->next != insertBefore) {
		curr = curr->next;
	}

	if (curr->next)
		newNode->next = curr->next;

	curr->next = newNode;
	return;

}
int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	res->next->next = new ListNode{ 3 };
	insertBefore(res, res->next, 6);

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