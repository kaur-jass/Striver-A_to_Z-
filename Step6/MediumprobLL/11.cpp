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
        vector<int> ans; 
        ListNode* temp = head; 
        while(temp != NULL)
        {
            ans.push_back(temp->val); 
            temp = temp->next; 
        }
        sort(ans.begin(),ans.end()); 
        if(ans.empty()) return nullptr;
        head = new ListNode(ans[0]);
        ListNode* mover = head;
        for(int i = 1; i < ans.size(); i++)
        {
            ListNode* temp = new ListNode(ans[i]); 
            mover->next = temp;
            mover = temp;
        }
        return head;
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