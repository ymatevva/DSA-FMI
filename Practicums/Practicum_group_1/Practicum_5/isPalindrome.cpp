#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<string>
using namespace std;


//Leetcode: 234
//https://leetcode.com/problems/palindrome-linked-list/description/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {

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
ListNode* split(ListNode* head) {

	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
bool isPalindrome(ListNode* head) {

	if (!head || !head->next) {
		return true;
	}
    ListNode* orig = head;
	ListNode* rev = reverseList(split(head));
	ListNode* secHalf = rev;
	
	while (secHalf) {
		if (orig->val != secHalf->val) {
			return false;
		}
		orig = orig->next;
		secHalf = secHalf->next;
	}
    reverseList(rev);
	return true;
}
int main() {

	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(1);
	std::cout << isPalindrome(head);
	return 0;
}
