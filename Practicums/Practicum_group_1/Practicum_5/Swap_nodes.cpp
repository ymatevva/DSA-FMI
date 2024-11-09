#include<iostream>
using namespace std;
//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/?envType=problem-list-v2&envId=awtok9rh

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

size_t listLen(ListNode* head) {
    size_t count = 0;
    ListNode* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

ListNode* swapNodes(ListNode* head, int k) {

    size_t len = listLen(head);
    if (k > len) {
        k = len;
    }

    if (!head) {
        return nullptr;
    }

    ListNode* first = head;
    ListNode* second = head;

    for (int i = 1; i < k; i++) {
        if (first)first = first->next;
    }

    for (int i = 1; i <= len - k; i++) {
        if (second)second = second->next;
    }

    if (first && second) {
        int tempVal = first->val;
        first->val = second->val;
        second->val = tempVal;
    }
    return head;
}

int main() {
	ListNode* head = new ListNode{ 1 };
	head->next = new ListNode{ 2 };
	head->next->next = new ListNode{ 2 };
	head->next->next->next = new ListNode{ 5 };

	ListNode* res = swapNodes(head,1);
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