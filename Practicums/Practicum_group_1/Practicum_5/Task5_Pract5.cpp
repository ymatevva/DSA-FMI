#include<iostream>
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/?envType=problem-list-v2&envId=anqpylct


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};


ListNode* removeDuplicates(ListNode* head) {
	if (!head) {
		return nullptr;
	}

	ListNode* curr = head;
	while (curr&& curr->next) {
		if (curr->val == curr->next->val) {
			curr->next = curr->next->next;
		}
		curr = curr->next;
	}
	return head;
}

int main() {
	ListNode* head = new ListNode{ 1 };
	head->next = new ListNode{ 2 };
	head->next->next = new ListNode{ 2 };
	head->next->next->next = new ListNode{ 5 };

	ListNode* res = removeDuplicates(head);
	ListNode* start = res;
	while (start) {
		std::cout << start->val << " ";
		start = start->next;
	}
	ListNode* iter = res;
	while (iter) {
		ListNode* toDel = iter;
		delete toDel;
		iter = toDel;
	}

	return 0;
}
