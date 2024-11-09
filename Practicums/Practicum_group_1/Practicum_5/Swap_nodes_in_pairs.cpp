#include<iostream>
using namespace std;


//https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=anqpylct


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

ListNode* swapNodes(ListNode* head) {
	if (!head|| !head->next) {
		return head;
	}

	ListNode* curr = head;
	while (curr&& curr->next) {
		int currVal = curr->val;
		curr->val = curr->next->val;
		curr->next->val = currVal;
		curr = curr->next->next;
	}
	return head;
}

int main() {
	ListNode* head = new ListNode{ 1 };
	head->next = new ListNode{ 2 };
	head->next->next = new ListNode{ 2 };
	head->next->next->next = new ListNode{ 5 };

	ListNode* res = swapNodes(head);
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