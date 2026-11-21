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
class Solution {
public:
       ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; 
        ListNode* zeroD = new ListNode(-1); 
        ListNode* oneD = new ListNode(-1); 
        ListNode* twoD = new ListNode(-1); 

        ListNode* zero = zeroD; 
        ListNode* one = oneD; 
        ListNode* two = twoD; 

        ListNode* curr = head; 

        while(curr != NULL)
        {
            if(curr->val == 0)
            {
                zero->next = curr; 
                zero = zero->next; 
            }
            else if(curr->val == 1)
            {
                one->next = curr; 
                one = one->next; 
            }
            else
            {
                two->next = curr; 
                two = two->next; 
            }
            curr = curr->next; 
        }

        //merge three sublists
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
        one->next = twoD->next; 
        two->next = NULL; 

        head = zeroD->next; 

        //delete dummy nodes
        delete zeroD; 
        delete oneD; 
        delete twoD; 

        return head;
     }
};
int main()
{
    vector<int> arr = {1,2,0, 1, 0, 2};
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