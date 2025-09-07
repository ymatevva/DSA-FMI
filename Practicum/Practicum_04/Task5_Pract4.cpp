#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

void fillValues(vector<int>& vec, Node* head) {

	Node* iter = head;
	while (iter) {
		vec.push_back(iter->val);
		iter = iter->next;
	}
}
int getMaxTwinSum(Node* head) {

	vector<int>values;
	fillValues(values, head);

	int maxTwinSum = INT_MIN;
	for (size_t i = 0; i < values.size(); i++)
	{
		int currSum = values[i] + values[values.size() - i - 1];
		if (currSum > maxTwinSum) {
			maxTwinSum = currSum;
		}
	}
	return maxTwinSum;

}

int main() {

	Node* test = new Node(4);
	test->next = new Node(2);
	test->next->next = new Node(2);
	test->next->next->next = new Node(3);

	std::cout << getMaxTwinSum(test);
	return 0;
}