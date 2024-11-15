#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

size_t getLen(Node* head) {
	if (!head) {
		return 0;
	}
	unsigned count = 0;
	Node* iter = head;
	while (iter) {
		count++;
		iter = iter->next;
	}
	return count;
}

Node* intersectionNode(Node* first, Node* second) {

	if (!first || !second) {
		return nullptr;
	}

	size_t firstLen = getLen(first);
	size_t secLen = getLen(second);

	Node* firstIter = first;
	Node* secIter = second;

	while (firstLen > secLen) {
		firstLen--;
		firstIter = firstIter->next;
	}

	while (firstLen < secLen) {
		secLen--;
		secIter = secIter->next;
	}

	while (firstIter && secIter) {
		if (firstIter == secIter) {
			return secIter;
		}
		secIter = secIter->next;
		firstIter = firstIter->next;
	}
	return nullptr;
}