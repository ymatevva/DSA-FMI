#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode():next(nullptr),val(0){}
	ListNode(ListNode* next, int val):next(next),val(val){}
	ListNode(int val):next(nullptr),val(val){}
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
void free(ListNode* head) {

	ListNode* curr = head;
	while (curr) {
		ListNode* next = curr->next;
		delete curr;
		curr = next;
	}
}

void print(ListNode* head) {

	ListNode* curr = head;
	while (curr) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}

}
int main() {

	ListNode* res = new ListNode{ 1 };
	res->next = new ListNode{ 2 };
	res->next->next = new ListNode{ 3 };
	ListNode* result = reverse(res);
	print(result);
	free(result);
	free(res);

	return 0;
}