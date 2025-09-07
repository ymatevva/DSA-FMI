#include<iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=problem-list-v2&envId=anqpylct
struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) :val(val), next(nullptr) {}
	ListNode(ListNode* next, int val) :val(val), next(next) {}
};


int maxTwinSum(ListNode* head) {

	vector<int>helpVec;

	ListNode* curr = head;
	unsigned ind = 0;
	while (curr) {
		helpVec.push_back( curr->val);
		ind++;
		curr = curr->next;
	}
  
	int maxSum = INT_MIN;
	for (size_t i = 0; i < ind; i++)
	{
		int currSum = helpVec[i] + helpVec[helpVec.size() - i - 1];
		if (currSum > maxSum) {
			maxSum = currSum;
		}
	}
	return maxSum;
}


int main() {
	ListNode* head = new ListNode{ 5 };
	head->next = new ListNode{ 4 };
	head->next->next = new ListNode{ 2 };
	head->next->next->next = new ListNode{ 1 };

	int result = maxTwinSum(head);
	cout << result << endl;
}
