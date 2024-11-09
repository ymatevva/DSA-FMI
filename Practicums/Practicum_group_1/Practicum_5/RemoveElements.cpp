#include<stack>
#include<vector>
#include<list>
#include<string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#include<stack>
#include<vector>
#include<list>
#include<string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {

	ListNode* start = head;
	ListNode* newList = head;
	while (start) {
		if (start->val != val) {
			//newList = start;
			newList->val = start->val;
		}
		newList = newList->next;
		start = start->next;
	}
	return start;
}

int main() {

	ListNode* head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(6);
	removeElements(head,3);
	return 0;
}