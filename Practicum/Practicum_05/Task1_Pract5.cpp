#include<iostream>
using namespace std;
//https://leetcode.com/problems/add-two-numbers/description/?envType=problem-list-v2&envId=awto6rpd

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};

ListNode* reverse(ListNode* head) {

	if (!head || !head->next) {
		return head;
	}

	ListNode* curr = head;
	ListNode* prev = nullptr;
	while (curr) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

ListNode* addTwoNums(ListNode* l1, ListNode* l2) {

	int helpVar = 0;
	ListNode* res = nullptr;

	while (l1 || l2 || helpVar) {

		int sum = helpVar;
		if (l1) {
			sum += l1->val;
			l1 = l1->next;
		}if (l2) {
			sum += l2->val;
			l2 = l2->next;
		}
		helpVar = sum / 10;
		ListNode* newNode = new ListNode(sum % 10);
		newNode->next = res;
		res = newNode;
	}
	return reverse(res);
}


int main() {
	ListNode* first = new ListNode{ 2 };
	first->next = new ListNode{ 4 };
	first->next->next = new ListNode{ 3 };

	ListNode* second = new ListNode{ 5 };
	second->next = new ListNode{ 6 };
	second->next->next = new ListNode{ 4 };

	ListNode* res = addTwoNums(first, second);
	ListNode* iter = res;
	while (iter) {
		std::cout << iter->val << " ";
		iter = iter->next;
	}

	ListNode* current = res;
	while (current)
	{
		ListNode* next = current->next;
		delete current;
		current = next;
	}
	return 0;
}
