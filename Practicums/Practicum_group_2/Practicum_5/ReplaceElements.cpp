#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};


void replace(ListNode* head, int numToRemove) {

	if (!head) {
		return;
	}

	ListNode* curr = head;
	while (curr) {
		if (curr->val == numToRemove) {
			ListNode* insertCurr = curr;
			curr->val = 1;
			for (size_t i = 1; i < numToRemove; i++)
			{
				ListNode* newNode = new ListNode{ 1 };
				insertCurr->next = newNode;
				insertCurr = insertCurr->next;
			}
			insertCurr->next = curr->next;
			curr = insertCurr->next;
		}
		curr = curr->next;
	}
	//return;
}


int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	res->next->next = new ListNode{ 3 };
	res->next->next->next = new ListNode{ 4 };
	res->next->next->next->next = new ListNode{ 5 };

	replace(res, 3);
	ListNode* start = res;
	while (start) {
		std::cout << start->val << " ";
		start = start->next;
	}
	ListNode* curr = res;
	while (curr) {
		ListNode* toDel = curr->next;
		delete curr;
		curr = toDel;
	}

	return 0;
}