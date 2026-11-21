#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    public:
    ListNode(int data1, ListNode* next1){
        val = data1; 
        next = next1; 
    }
    ListNode(int data1){
        val = data1; 
        next = nullptr; 
    }
};
ListNode* convertArraytoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;
    for(int i = 1; i < arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i], nullptr); 
        prev->next = temp; 
        prev = temp;
    }
    return head;
}

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
       // Using Merge Sort Algorithm
         if(!head || !head->next) return head;
        // Find the middle point
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // Split the list into two halves
        // Recursively sort the two halves
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        // Merge the sorted halves
        return merge(l1, l2);
    }
};
int main()
{
    vector<int> arr = {4, 2, 1, 3};
    ListNode* head = convertArraytoLL(arr);
    Solution sol; 
    ListNode* sortedHead = sol.sortList(head);
    ListNode* temp = sortedHead; 
    while(temp != NULL)
    {
        cout << temp->val << " "; 
        temp = temp->next; 
    }
}