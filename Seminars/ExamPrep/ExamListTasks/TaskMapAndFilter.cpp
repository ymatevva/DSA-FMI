#include<iostream>
#include<functional>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node() = default;
	Node(int data, Node* next = nullptr) :data(data), next(next) {}
};


int multByThree(int num) {
	return num * 2;
}

void mapFunction(Node* head, function<int(int)>func) {

	Node* iter = head;
	while (iter) {
		iter->data = func(iter->data);
		iter = iter->next;
	}
}

void free(Node* head) {
	Node* iter = head;
	while (iter) {
		Node* del = iter;
		iter = iter->next;
		delete del;
	}
}

void print(Node* head) {
	Node* iter = head;
	while (iter) {
		std::cout << iter->data << " ";
		iter = iter->next;
	}
}

template<class Predicate>
Node* filterFunction(Node* head, const Predicate& pred) {

	if (!head) {
		return nullptr;
	}

	Node* res = new Node();
	Node* iter = res;

	while (head) {
		if (pred(head->data)) {
			iter->next = new Node(head->data);
			iter = iter->next;
		}
		head = head->next;
	}
	return res->next;
}
int main() {
	Node* n = new Node(3, new Node(7, new Node(9, new Node(10, new Node(11)))));

	//mapFunction(n, multByThree);
	//print(n);
	//free(n);

	Node* newNode = filterFunction(n, [](int el) { return el % 2 == 0; });
	print(newNode);
	free(newNode);
}