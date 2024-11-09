#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :next(nullptr), val(0) {}
	ListNode(ListNode* next, int val) :next(next), val(val) {}
	ListNode(int val) :next(nullptr), val(val) {}
};


bool hasCycle(ListNode* head) {

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			return true;
		}
	}
	return false;
}


int main() {
	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	res->next->next = new ListNode{ 3 };
	res->next->next->next = res->next;
	std::cout << hasCycle(res);
}