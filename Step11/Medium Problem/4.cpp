#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int _val) {
        val = _val;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); 
        priority_queue<int, vector<int>, greater<int>> heap; 
        for(int i = 0; i<n; i++){
            ListNode *temp = lists[i]; 
            while(temp != NULL){
                heap.push(temp->val); 
                temp = temp->next; 
            }
        }
        ListNode *dummy = new ListNode(-1); 
        ListNode *ans = dummy; 
        int i = 0; 
        while(!heap.empty()){
            ans->next = new ListNode(heap.top());
            heap.pop(); 
            ans = ans->next;
            i++; 
        }
        return dummy->next; 
    }
};

// Driver program to test the above methods.
int main() {
    // Example usage:
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);

    // Print merged list
    ListNode* temp = mergedList;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}