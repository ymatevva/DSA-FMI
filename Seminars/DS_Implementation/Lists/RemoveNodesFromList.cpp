#include<iostream>
using namespace std;


struct Node {
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) :data(data), next(next) {}
};

template<typename Predicate>
Node* removeNodes(Node* head,Predicate predicate) {
	if (!head || !head->next) {
		return nullptr;
	}

	Node** iter = &head;

	while (*iter) {

		if (predicate((*iter)->data)) {
			Node* del = *iter;
			*iter = (*iter)->next;
			delete del;
		}

		iter = &(*iter)->next;
	}
	return head;
}

void print(Node* head) {
	if (!head) {
		return;
	}

	Node* iter = head;
	while (iter) {
		std::cout << iter->data << " ";
		iter = iter->next;
	}
}

void free(Node* head) {
	if (!head) {
		return;
	}

	Node* iter = head;
	while (iter) {
		Node* del = iter;
		iter = iter->next;
		delete del;
	}
}

bool isOdd(int num) {
	return num % 2 == 1;
}
int main() {

	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	Node* filteredList = removeNodes(start,isOdd);
	print(filteredList);

}