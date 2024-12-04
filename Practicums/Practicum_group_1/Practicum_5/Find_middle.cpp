#include<iostream>
using namespace std;

//Leetcode: 876
// https://leetcode.com/problems/middle-of-the-linked-list/description/
struct ListNode {
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr){}
	ListNode(int val):val(val),next(nullptr){}
	ListNode(ListNode* next, int val) :val(val),next(next){}
};


ListNode* findMid(ListNode* head) {

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	res->next->next = new ListNode{ 3 };
	ListNode* mid = findMid(res);
	std::cout << mid->val;

}
