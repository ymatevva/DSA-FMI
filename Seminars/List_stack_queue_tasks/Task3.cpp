#include <iostream>
#include <string>
using namespace std;

struct Node
{
	Node(int value, Node* next) : value(value), next(next) {}
	int value;
	Node* next;
};

void print(Node* list)
{
	Node* iter = list;
	while (iter != nullptr)
	{
		cout << iter->value << " ";
		iter = iter->next;
	}
}

void freeList(Node* list)
{
	Node* iter = list;
	while (iter)
	{
		Node* next = iter->next;
		delete iter;
		iter = next;
	}
}

unsigned countDigits(int num) {
	unsigned count = 0;
	while (num != 0) {
		count++;
		num /= 10;
	}
	return count;
}
bool isWithThreeDigits(int num) {
	return countDigits(num) == 3;
}
template<typename Comparator>
Node* rearrange(Node* head, const Comparator& comparator) {
	if (!head) {
		return nullptr;
	}

	Node* trueBeg;
	Node* trueEnd;
	Node* falseBeg;
	Node* falseEnd;
	trueBeg = trueEnd = falseBeg = falseEnd = nullptr;

	Node* iter = head;
	while (iter) {
		if (comparator(iter->value)) {
			if (!trueBeg) {
				trueBeg = trueEnd = iter;
			}
			else {
				trueEnd->next = iter;
				trueEnd = iter;
			}
		}else {
			if (!falseBeg) {
				falseBeg = falseEnd = iter;
			}
			else {
				falseEnd->next = iter;
				falseEnd = iter;
			}
		}
		iter = iter->next;
	}

	if (trueEnd) {
		trueEnd->next = falseBeg;
	}if (falseEnd) {
		falseEnd ->next = nullptr;
	}

	return trueBeg ? trueBeg : falseBeg;
}

int main() {

	Node* test = new Node(123,new Node(22,new Node(398,new Node(41,new Node(5,new Node(698,nullptr))))));
	rearrange(test, isWithThreeDigits);
	print(test);
	return 0;
}
