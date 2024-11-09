#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr){}
	ListNode(int val):val(val),next(nullptr){}
	ListNode(ListNode* next, int val) :val(val),next(next){}
};

size_t getLen(ListNode* first) {

	size_t count = 0;
	while (first) {
		count++;
		first = first->next;
	}
	return count;
}

ListNode* intersectionNode(ListNode* l1, ListNode* l2) {

	if (!l1 || !l2) {
		return nullptr;
	}

	size_t size1 = getLen(l1);
	size_t size2 = getLen(l2);

	while (size1 > size2) {
		l1 = l1->next;
		size1--;
	}

	while (size1 < size2) {
		l2 = l2->next;
		size2--;
	}

	while (l1 && l2) {
		if (l1 == l2) {
			return l1;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return nullptr;
}
int main() {

	ListNode* first = new ListNode{ 4 };
	first->next = new ListNode{ 1 };
	first->next->next = new ListNode{ 8 };
	first->next->next->next = new ListNode{ 4 };
	first->next->next->next->next = new ListNode{ 5 };


	ListNode* second = new ListNode{ 5 };
	second->next = new ListNode{ 6 };
	second->next->next = new ListNode{ 1 };
	second->next->next->next = first->next->next;  



	ListNode* res = intersectionNode(first, second);
	std::cout << res->val;

}