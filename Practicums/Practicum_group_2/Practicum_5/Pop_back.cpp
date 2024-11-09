#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

void pop_back(ListNode*& head) {

	if (!head) {
		return;
	}

	ListNode* curr = head;
	while (curr->next->next) {
		curr = curr->next;
	}

	ListNode* toDel = curr->next;
	curr->next = nullptr;
	delete toDel;

	return;

}
int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	//res->next->next = new ListNode{ 3 };
	pop_back(res);


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