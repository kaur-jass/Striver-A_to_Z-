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
    ListNode* mover = head;
    for(int i = 1; i < arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i]); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int cnt = 1; 
        ListNode* tail = head; 
        while(tail->next != NULL){
            cnt++; 
            tail= tail->next;
        }
        k = k%cnt; 
        if(k==0) return head; 
        tail->next = head; 
        int steps = cnt-k;
        while(steps--){ 
            tail = tail->next; 
        }
        head = tail->next; 
        tail->next = NULL; 
        return head;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = convertArraytoLL(arr);
    Solution sol;
    head = sol.rotateRight(head, 2);
    // Print the linked list
    ListNode* temp = head;
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}





