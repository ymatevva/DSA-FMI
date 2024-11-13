#include<iostream>
using namespace std;
struct SinglyNode {
	int val;
	SinglyNode* next;
	SinglyNode(int val,SinglyNode* next):val(val),next(next){}
};


struct DoublyNode {
	SinglyNode* value;
	DoublyNode* prev;
	DoublyNode* next;
	DoublyNode(SinglyNode* value):value(value), next(nullptr), prev(nullptr) {}
};


void free(DoublyNode* head) {
	if (!head) {
		return;
	}

	DoublyNode* iter = head;
	while (iter) {

		free(iter->value);
		DoublyNode* toDel = iter;
		iter = iter->next;
		delete toDel;
	}
}

void free(SinglyNode* head) {
	SinglyNode* iter = head;
	while (iter) {
		SinglyNode* toDel = iter;
		iter = iter->next;
		delete toDel;
	}
}

DoublyNode* midList(DoublyNode* head) {
	if (!head || !head->next) {
		return head;
	}

	DoublyNode* fast = head;
	DoublyNode* slow = head;
	while (fast&& slow&& fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

unsigned calculateNumber(SinglyNode* head) {

	if (!head) {
		return 0;
	}
	unsigned res = 0;
	SinglyNode* iter = head;
	while (iter) {
		(res *= 10) += iter->val;
		iter = iter->next;
	}
	return res;
}

bool check(DoublyNode* head) {

	if (!head) {
		return false;
	}

	DoublyNode* iter = head;
	DoublyNode* mid = midList(head);

	while (iter != mid) {

		if (calculateNumber(iter->value) > calculateNumber(iter->next->value)) {
			return false;
		}
		iter = iter->next;
	}
	iter = mid;
	while (iter&&iter->next) {
		if (calculateNumber(iter->value) < calculateNumber(iter->next->value)) {
			return false;
		}
		iter = iter->next;
	}
	return true;
}

int main() {

	SinglyNode* l1 = new SinglyNode(3, new SinglyNode(4, new SinglyNode(1, nullptr)));

	SinglyNode* l2 = new SinglyNode(5, new SinglyNode(5, new SinglyNode(1, new SinglyNode(4, nullptr))));
	SinglyNode* l3 = new SinglyNode(9, new SinglyNode(9, new SinglyNode(9, new SinglyNode(9, nullptr))));

	SinglyNode* l4 = new SinglyNode(9, new SinglyNode(5, new SinglyNode(2, new SinglyNode(9, nullptr))));
	SinglyNode* l5 = new SinglyNode(9, new SinglyNode(9, new SinglyNode(4, new SinglyNode(4, nullptr))));
	SinglyNode* l6 = new SinglyNode(3, new SinglyNode(4, nullptr));

	DoublyNode* d1 = new DoublyNode(l1);
	DoublyNode* d2 = new DoublyNode(l2);
	DoublyNode* d3 = new DoublyNode(l3);//s
	DoublyNode* d4 = new DoublyNode(l4);
	DoublyNode* d5 = new DoublyNode(l5);//f
	DoublyNode* d6 = new DoublyNode(l6);
	d1->prev = nullptr;
	d1->next = d2;
	d2->prev = d1;
	d2->next = d3;
	d3->prev = d2;
	d3->next = d4;
	d4->next = d5;
	d4->prev = d3;
	d5->next = d6;
	d5->prev = d4;
	d6->prev = d5;
	d6->next = nullptr;

	std::cout << check(d1);
}