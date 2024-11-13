#include <iostream>
#include <list>
#include <queue>
using namespace std;

void merge(queue<int>& q1, queue<int>& q2) {

	while (!q2.empty()) {
		q1.push(q2.front());
		q2.pop();
	}
}

void makeEqual(queue<int>& q1, queue<int>& q2) {

	if (q1.size() > q2.size()) {
		while (q1.size() > q2.size() + 1) {
			q2.push(q1.front());
			q1.pop();
		}
	}
	else {
		while (q2.size() > q1.size() + 1) {
			q1.push(q2.front());
			q2.pop();
		}
	}
}

void modifyList(list<queue<int>>& myList) {

	if (myList.empty() || myList.size() == 1) {
		return;
	}

	auto iter = myList.begin();

	while (iter != myList.end()) {

		auto next = iter;
		++next;

		if (next == myList.end())
			break;

		if (iter->size() == next->size()) {
			merge(*iter, *next);
			myList.erase(next);
			continue;
		}
		else {
			++iter;
			if (++next == myList.end())
				break;

			if (!(iter->size() == next->size())) {
				{
					makeEqual(*iter, *next);
					++iter;
				}

			}
		}
	}
}




void print(list<queue<int>>& l) {

	for (auto it = l.begin(); it != l.end(); it++)
	{
		queue<int>tmp = *it;
		while (!tmp.empty()) {
			std::cout << tmp.front() << " ";
			tmp.pop();
		}
		std::cout << endl;
	}
}
	int main() {

		list<queue<int>> l;

		queue<int> q1;
		q1.push(2);
		q1.push(4);
		q1.push(6);
		queue<int> q2;
		q2.push(8);
		q2.push(0);
		q2.push(7);
		queue<int> q3;
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

		l.push_back(q1);
		l.push_back(q2);
		l.push_back(q3);
		l.push_back(q4);
		l.push_back(q5);
		l.push_back(q6);
		l.push_back(q7);

		modifyList(l);
		print(l);
		return 0;
	}