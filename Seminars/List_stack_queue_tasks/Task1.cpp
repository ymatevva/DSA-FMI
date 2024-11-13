#include<iostream>
#include<cstring>
using namespace std;

struct Node {

	string str;
	Node* next;
	Node(string str) :str(str),next(nullptr) {}
};

void print(Node* list) {

	Node* iter = list;
	do {//while w do not reach the start pf the cycle again

		std::cout << iter->str << " ";
		iter = iter->next;
	} while (list != iter);

}

bool isMatch(const string& first,const string& second) {

	if (first.empty() || second.empty()) {
		return false;
	}

	return first[first.size() - 1] == second[0];
}

void makeAUnion(Node* first, Node* second) {

	first->str += '-' + second->str;
	first->next = second->next;
	delete second;
}


void free(Node* list) {

	Node* iter = list;
	do {
		Node* curr = iter;
		iter = iter->next;
		delete curr;
	} while (iter != list);
}

Node* unite(Node* list) {

	Node* iter = list;

	Node* lexMin = list;

	bool end = false;
	while (!end) {

		if (strcmp(iter->str.c_str(), lexMin->str.c_str()) < 0) {
			lexMin = iter;//searching for the minimum element
		}
			
		Node* next = iter->next;
		if (next == list) {
			end = true;//cycle found
		}

		if (iter != next && isMatch(iter->str, next->str)) {
			makeAUnion(iter, next);
		}
		else {
			iter = iter->next;
		}
	}
	return lexMin;//returns the start of the new list ordered lexicographically
}

int main() {

	Node* f1 = new Node("street");
	Node* f2 = new Node("taxi");
	Node* f3 = new Node("inc");
	Node* f4 = new Node("dog");
	Node* f5 = new Node("smile");
	Node* f6 = new Node("eat");
	Node* f7 = new Node("tall");
	Node* f8 = new Node("pass");

	f1->next = f2;
	f2->next = f3;
	f3->next = f4;
	f4->next = f5;
	f5->next = f6;
	f6->next = f7;
	f7->next = f8;
	f8->next = f1;

	Node* result = unite(f1);
	print(result);
	free(result);
	return 0;
}