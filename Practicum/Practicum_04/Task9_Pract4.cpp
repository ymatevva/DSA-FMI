#include<iostream>
using namespace std;

//max occured element in list
struct Node {
	int val;
	Node* next;
	Node(int val,Node* next) :val(val), next(next) {}
};

int getMaxElement(Node* head) {
	if (!head) {
		return INT_MIN;
	}

	int maxOccEl = head->val;
	int maxOcc = INT_MIN;
	
	Node* iter = head;
	while (iter) {

		Node* curr = iter;
		int currVal = curr->val;
		int currOcc = 0;
		while (curr) {
			if (curr->val == currVal) {
				currOcc++;
			}
			curr = curr->next;
		}
		if (currOcc > maxOcc) {
			maxOcc = currOcc;
			maxOccEl = currVal;
		}
		iter = iter->next;
	}
	return maxOccEl;
}

int main() {

	Node* test = new Node(1,new Node(2,new Node(0,new Node(9,new Node(2,nullptr)))));
	std::cout << getMaxElement(test);

	return 0;
}

