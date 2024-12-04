#include<iostream>
using namespace stdl;
//Leetcode: 86
//https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=atttgh4c


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

    void push_back(ListNode*& beg, ListNode*& end, int val){

        ListNode* toAdd = new ListNode(val);

        if(!beg){
            beg = end = toAdd;
        }else{
            end->next = toAdd;
            end = toAdd;
        }
        
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* trueB = nullptr;
        ListNode* trueE= nullptr;
        ListNode* falseB = nullptr;
        ListNode* falseE = nullptr;

        while(head){
           if(x > head->val ){
            push_back(trueB,trueE,head->val);
           }else{
             push_back(falseB,falseE,head->val);
           }
           head = head->next;
        }

        if(trueB){
           trueE->next = falseB;
        }
        if(falseB){
            falseE->next = nullptr;
        }
        return trueB ? trueB : falseB;
    }

int main(){

ListNode* list = new ListNode(2);
list->next = new ListNode(7);
list->next->next = new ListNode(1);

partition(list,3);
//print func
}
