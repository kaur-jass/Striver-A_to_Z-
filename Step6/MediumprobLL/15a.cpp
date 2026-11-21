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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1; 
    ListNode* temp2 = l2; 
    int carry = 0; 
    ListNode* head = new ListNode(0); 
    ListNode* temp3 = head; 
    while(temp1 != NULL || temp2 != NULL || carry){
        int sum = 0; 
        sum += carry; 
        if(temp1 != NULL){
            sum += temp1->val; 
            temp1 = temp1->next;
        }
        if(temp2 != NULL){
            sum += temp2->val; 
            temp2 = temp2->next;
        }   
        carry = sum/10; 
        temp3->next = new ListNode(sum%10);
        temp3 = temp3->next;
    }
    return head->next;
}


int main()
{
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    ListNode* head = convertArraytoLL(arr);
    vector<int> arr2 = {6, 5, 4};
    ListNode* head2 = convertArraytoLL(arr2);
    ListNode* intersectionNode = addTwoNumbers(head, head2);
    while(intersectionNode != NULL){
        cout << intersectionNode->val << " ";
        intersectionNode = intersectionNode->next;
    }
    return 0;
}


