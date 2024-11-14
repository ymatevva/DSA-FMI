#include<iostream>
#include<list>
#include<queue>
using namespace std;

void merge(queue<int>& q1, queue<int>& q2) {

	if (q2.empty()) {
		return;
	}
	while (!q2.empty()) {
		q1.push(q2.front());
		q2.pop();
	}
}


bool equalize(queue<int>& q1, queue<int>& q2) {

	if (q2.empty()) {
		return false;
	}

	if (q1.size() > q2.size() + 1) {

		while (q1.size() > q2.size() + 1) {
			q2.push(q1.front());
			q1.pop();
		}
		return true;
	}
	else if (q2.size() > q1.size() + 1) {

		while (q2.size() > q1.size() + 1) {
			q1.push(q2.front());
			q2.pop();
		}
		return true;
	}
	return false;
}

void transform(list<queue<int>>& myList) {

	if (!myList.size()) {
		return;
	}

	auto end = myList.end();
	auto next = myList.begin();

	while (true) {

		auto curr = next++;
		if (next == end) {
			break;
		}
		if ((*curr).size() == (*(next)).size()) {
			merge(*curr, *(next));
			myList.erase(next);
			next = curr;
		}
		else {

			if (equalize(*curr, *(next))) {

				++next;
				if (next == end) {
					break;
				}
			}
		}

	}
}
void printQueue(queue<int>& myQ) {
	for (size_t i = 0; i < myQ.size(); i++)
	{
		int cuur = myQ.front();
		std::cout << cuur << " ";
		myQ.pop();
		myQ.push(cuur);
	}
	std::cout << std::endl;
}

void printList(list<queue<int>>& myL) {
	auto beg = myL.begin();
	auto end = myL.end();
	for (auto it = beg; it != end; it++)
	{
		printQueue(*it);
	}
}
int main() {

	list<queue<int>> myList;

	queue<int> q1;
	q1.push(2);
	q1.push(4);
	q1.push(6);

	queue<int> q2;
	q2.push(8);
	q2.push(0);
	q2.push(7);

	queue<int>q3;
	q3.push(5);
	q3.push(7);
	q3.push(9);
	q3.push(23);
	q3.push(22);

	queue<int> q4;
	q4.push(9);
	q4.push(1);

	queue<int> q5;
	q5.push(2);

	queue<int> q6;
	q6.push(1);

	queue<int> q7;
	q7.push(33);
	q7.push(44);

	myList.push_back(q1);
	myList.push_back(q2);
	myList.push_back(q3);
	myList.push_back(q4);
	myList.push_back(q5);
	myList.push_back(q6);
	myList.push_back(q7);

	printList(myList);
	transform(myList);
	printList(myList);
	return 0;
}
