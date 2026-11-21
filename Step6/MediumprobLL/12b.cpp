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
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            if(curr->val == 0) cnt0++;
            else if(curr->val == 1) cnt1++;
            else cnt2++;
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL)
        {
            if(cnt0 > 0)
            {
                curr->val = 0;
                cnt0--;
            }
            else if(cnt1 > 0)
            {
                curr->val = 1;
                cnt1--;
            }
            else
            {
                curr->val = 2;
                cnt2--;
            }
            curr = curr->next;
        }
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