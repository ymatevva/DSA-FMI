#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//Leetcode: 23
//https://leetcode.com/problems/merge-k-sorted-lists/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<int, vector<int>, greater<int>> myPQ;
    for (int i = 0; i < lists.size(); i++) {

        ListNode* iter = lists[i];
        while (iter) {
            myPQ.push(iter->val);
            iter = iter->next;
        }
    }

    ListNode* head = new ListNode;
    ListNode* iter = head;;

    while (myPQ.size()) {

        ListNode* add = new ListNode(myPQ.top());
        myPQ.pop();
        iter->next = add;
        iter = iter->next;
    }

    return head->next;
}


ListNode* createList(const vector<int>& values) {
    ListNode* head = new ListNode();
    ListNode* iter = head;
    for (int val : values) {
        iter->next = new ListNode(val);
        iter = iter->next;
    }
    return head->next;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<ListNode*> lists;
    lists.push_back(createList({ 1, 4, 5 }));
    lists.push_back(createList({ 1, 3, 4 }));
    lists.push_back(createList({ 2, 6 }));

    
    ListNode* mergedList = mergeKLists(lists);

    printList(mergedList);

}