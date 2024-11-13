#include<iostream>
using namespace std;


struct SinglyNode {
	int val;
	SinglyNode* next;
	SinglyNode(int val,SinglyNode* next):next(next),val(val){}
	SinglyNode(int val):val(val),next(nullptr){}
};


bool isEven(int num) {
	return num % 2 == 0;
}

//Complexity by time: 0(n)//Complexity by space:0(n)
//void  rearange(SinglyNode*& head) {
//	if (!head) {
//		return;
//	}
//
//	SinglyNode* iter = head;
//
//	SinglyNode start(0);
//	SinglyNode* res = &start;
//
//	while (iter) {
//		if (isEven(iter->val)) {
//			res->next = new SinglyNode(iter->val);
//			res = res->next;
//		}
//		iter = iter->next;
//	}
//
//	iter = head;
//	
//	while (iter) {
//		if (!isEven(iter->val)) {
//			res->next = new SinglyNode(iter->val);
//			res = res->next;
//		}
//		iter = iter->next;
//	}
//
//	head = start.next;
//}



//Complexity by time: 0(n)//Complexity by space:0(1)
SinglyNode* rearange(SinglyNode*& head) {
	if (!head) {
		return nullptr;
	}

	SinglyNode* iter = head;
	SinglyNode* firstEven;
	SinglyNode* firstOdd;
	SinglyNode* lastEven;
	SinglyNode* lastOdd;

	firstEven = firstOdd = lastEven = lastOdd = nullptr;


	while (iter) {

		if (isEven(iter->val)) {

			if (!firstEven) {
				firstEven = lastEven = new SinglyNode(iter->val);
			}
			else {
				lastEven->next = iter;
				lastEven = iter;
			}
		}
		else {
			if (!firstOdd) {
				firstOdd = lastOdd = new SinglyNode(iter->val);
			}
			else {
				lastOdd->next = iter;
				lastOdd = iter;
			}
		}
		iter = iter->next;
	}

	if (lastEven) {
		lastEven->next = firstOdd;
	}
	if (lastOdd) {
		lastOdd->next = nullptr;
	}

	return lastEven ? firstEven : firstOdd;
	
}

void print(SinglyNode* head) {
	if (!head) {
		return;
	}

	SinglyNode* iter = head;
	while (iter) {
		std::cout << iter->val << " ";
		iter = iter->next;
	}
}


int main() {


	SinglyNode* res = new SinglyNode(3);
	res->next = new SinglyNode(5);
	res->next->next = new SinglyNode(2);
	res->next->next->next = new SinglyNode(9);
	res->next->next->next->next = new SinglyNode(4);

	print(rearange(res));
	free(res);
	return 0;
}