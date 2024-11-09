#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

void delete_before(ListNode* head, ListNode* deleteBefore) {

	if (!head || !deleteBefore|| head == deleteBefore) {
		return;
	}

	ListNode* curr = head;
	while (curr && curr->next!= deleteBefore) {
		curr = curr->next;
	}

	if (curr) {
		ListNode* toDel = curr->next;
		curr->next = curr->next->next;
		delete toDel;
	}

	return;
}
int main() {

	ListNode* res = new ListNode{ 1 };
	//res->next = new ListNode{ 2 };
	//res->next->next = new ListNode{ 3 };
	delete_before(res, res);


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