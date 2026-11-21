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
       // Using Merge Sort Algorithm
         if(!head || !head->next) return head;
        // Find the middle point
        ListNode* zero = nullptr;
        ListNode* one = nullptr;
        ListNode* two = nullptr;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->val == 0)
            {
                if(zero == nullptr)
                {
                    zero = new ListNode(0);
                }
                else
                {
                    ListNode* mover = zero;
                    while(mover->next != NULL)
                    {
                        mover = mover->next;
                    }
                    mover->next = new ListNode(0);
                }
            }
            else if(temp->val == 1)
            {
                if(one == nullptr)
                {
                    one = new ListNode(1);
                }
                else
                {
                    ListNode* mover = one;
                    while(mover->next != NULL)
                    {
                        mover = mover->next;
                    }
                    mover->next = new ListNode(1);
                }
            }
            else
            {
                if(two == nullptr)
                {
                    two = new ListNode(2);
                }
                else
                {
                    ListNode* mover = two;
                    while(mover->next != NULL)
                    {
                        mover = mover->next;
                    }
                    mover->next = new ListNode(2);
                }
            }
            temp = temp->next;
        }
        // Merge the three lists
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        if(zero)
        {
            tail->next = zero;
            while(tail->next != NULL)
            {
                tail = tail->next;
            }
        }
        if(one)
        {
            tail->next = one;
            while(tail->next != NULL)
            {
                tail = tail->next;
            }
        }
        if(two)
        {
            tail->next = two;
        }
        return dummy->next;
        
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