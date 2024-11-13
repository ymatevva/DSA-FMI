#include<iostream>
#include<list>
#include<queue>
using namespace std;


bool isSortedQueue(queue<int>& myQueue, int& lastEl) {

	if (myQueue.empty())
		return true;

	for (size_t i = 0; i < myQueue.size(); i++)
	{
		int currEl = myQueue.front();
		myQueue.pop();
		int nextEl = myQueue.front();

		if (i == myQueue.size()) {
			lastEl = currEl;
		}
		if (i != myQueue.size() && currEl > nextEl) {
			return false;
		}
		myQueue.push(currEl);
	}
	return true;
}

bool isSortedList(list<queue<int>>& myList) {


	int lastElement = INT_MIN;//with this we wil compare the next elements and will upgrade this var accordingly

	for (auto it = myList.begin(); it != myList.end(); it++)
	{
			if (it != myList.begin() && !(*it).empty() && (*it).front() < lastElement){// here this is not the first queue// the queue is not empty and its first element is smaller than the previous lastEl in the last queue
				return false;
			}
			if (!isSortedQueue(*it, lastElement)) {
				return false;
		   }	
	}
	return true;
}

int main() {


	list<queue<int>> test;

	queue<int>q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);

	queue<int>q2;
	q2.push(6);
	q2.push(3);
	q2.push(10);

	test.push_back(q1);
	test.push_back(q2);


	std::cout << isSortedList(test);
	return 0;
}