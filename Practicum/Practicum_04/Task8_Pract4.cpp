#include<iostream>
using namespace std;

//https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=anqpylct
struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

Node* swapNodesInPairs(Node* head) {
     
      if(!head || !head->next){
        return head;
      }

      ListNode* curr = head;
      ListNode* afterCurr = curr->next;
 
      curr->next=afterCurr->next;
      afterCurr->next = curr;
      curr->next = swapPairs(curr->next);

      return afterCurr;
}
int main() {
	Node* test = new Node(1);
	test->next = new Node(2);
	test->next->next = new Node(2);
	test->next->next->next = new Node(3);
	  
	Node* result = swapNodesInPairs(test);
	while (result) {
		std::cout << result->val << " ";
		result = result->next;
	}
	return 0;
}
