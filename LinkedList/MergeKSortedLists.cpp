// ! Time : O(nlogk) -: k is number of lists
// ! Space: O(1) 
#include <bits/stdc++.h>
using namespace std;


// ! Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    struct compare{
      
        bool operator()(ListNode* f,ListNode* s){
            return f->val > s->val;
        }
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
//         Making a Priority queue with Compare structure
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;
        
//         Putting all starting linkedList from each group
        for(auto list: lists){
            if(list)
                pq.push(list);
        }
        
        if(pq.empty()) return NULL;
        // take out first min data List
        ListNode* head = pq.top();
        pq.pop();
        
//         Add next data list if present in that list
        if(head->next) 
                pq.push(head->next);
        
        ListNode* tail = head;
        
        while(!pq.empty()){
            // popping out next min and add to tail
            tail->next = pq.top();
            pq.pop();
            
            tail = tail->next;
            
//             push into pq if next present
            if(tail->next) 
                pq.push(tail->next);          
            
            
        }
        
        return head;
        
    }
};
