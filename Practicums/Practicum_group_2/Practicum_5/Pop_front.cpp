#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

void pop_front(ListNode*&head) {

	if (!head) {
		return;
	}

	ListNode* toDel = head;
	head = head->next;
	delete toDel;
	return;

}
int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	//res->next->next = new ListNode{ 3 };
	pop_front(res);


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