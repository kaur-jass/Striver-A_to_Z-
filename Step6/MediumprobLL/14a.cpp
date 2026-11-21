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
void reverse(ListNode*& head){
    ListNode* prev = nullptr; 
    ListNode* curr = head; 
    while(curr != nullptr)
    {
        ListNode* next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    }
    head = prev;
}
ListNode *plusOne(ListNode *headA) {
     // Implementation of plusOne function
    reverse(headA);
    ListNode* temp = headA;
    int carry = 1;
    while(temp != NULL && carry > 0){
        int sum = temp->val + carry;
        temp->val = sum % 10;
        carry = sum / 10;
        if(temp->next == NULL && carry > 0){
            temp->next = new ListNode(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    reverse(headA);
    return headA;
}
int main()
{
    vector<int> arr = {9,9,9};
    ListNode* head = convertArraytoLL(arr);
    ListNode* result = plusOne(head);
    ListNode* temp = result;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}