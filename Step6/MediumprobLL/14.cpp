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
ListNode *plusOne(ListNode *headA) {
     // Implementation of plusOne function
    vector<int> digits;
    ListNode* temp = headA;
    while(temp != NULL){
        digits.push_back(temp->val); 
        temp = temp->next;
    }

    int n = digits.size();
    int sum = 0;  
    int carry = 0; 
    carry = (digits[n-1]+1)/10;
    digits[n-1] = (digits[n-1]+1)%10; 
    for(int i = n-2; i>=0; i--){
        sum = digits[i]+carry;
        carry = sum/10;
        digits[i] = sum%10;            
    } 
    if(carry){
        digits.insert(digits.begin(), carry);  // for resizing it properly.... 
    }
    // Convert the digits back to linked list
    ListNode* newHead = new ListNode(digits[0]);
    ListNode* mover = newHead;
    for(int i = 1; i < digits.size(); i++){
        ListNode* temp = new ListNode(digits[i], nullptr); 
        mover->next = temp; 
        mover = temp;
    }
    return newHead;        
}


int main()
{
    vector<int> arr = {9,9,9};
    ListNode* head = convertArraytoLL(arr);
    ListNode* result = plusOne(head);
    ListNode* temp = result;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}

