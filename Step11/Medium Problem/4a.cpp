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

struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val; 
    }
}; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); 
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap; 
        for(auto list : lists){
            if(list) heap.push(list);  // Pushing only heads of the lists in the minheap conating listnodes 
        }
        // Repeat 
        // pop the smallest node, attach it to the ans, and push its next node(if exists)
        ListNode* dummy = new ListNode(-1); 
        ListNode* node = dummy; 
        while(!heap.empty()){
            node->next = heap.top(); 
            heap.pop(); 
            node = node->next; 
            if(node->next) heap.push(node->next); 
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