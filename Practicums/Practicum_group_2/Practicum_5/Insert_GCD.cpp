#include<iostream>
using namespace std;


//https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(), next(nullptr) {}
    ListNode(int val) :val(val), next(nullptr) {}
    ListNode(ListNode* next, int val) :val(val), next(next) {}
};

int GCD(int a, int b) {

    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
ListNode* insertGreatestCommonDivisors(ListNode* head) {

    if (!head || !head->next) {
        return head;
    }

    ListNode* curr = head;
    while (curr->next) {

        int currVal = curr->val;
        int nextVal = curr->next->val;
        int gcdOfTwo = GCD(currVal, nextVal);

        ListNode* newEl = new ListNode(gcdOfTwo);

        newEl->next = curr->next;
        curr->next = newEl;
        curr = newEl;

        curr = curr->next;
    }
    return head;
}


int main() {

    ListNode* res = new ListNode{ 18 };
    res->next = new ListNode{ 6 };
    res->next->next = new ListNode{ 10 };
    res->next->next->next = new ListNode{ 3 };

    insertGreatestCommonDivisors(res);


    ListNode* printRes = res;
    while (printRes) {
        std::cout << printRes->val << " ";
        printRes = printRes->next;
    }

    ListNode* del = res;
    while (del) {
        ListNode* toDel = del->next;
        delete del;
        del = toDel;
    }

    return 0;
}