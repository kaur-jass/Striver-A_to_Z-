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
    void reverse(ListNode* head, int k,ListNode*& groupHead,ListNode*& nextgroupHead,ListNode*& groupTail){
        ListNode* prev = NULL;
        ListNode* curr = head;
        groupTail = head;
        for(int i = 1; i<=k; i++)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next; 
        }
        groupHead = prev; 
        nextgroupHead = curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 1; 
        ListNode* temp = head; 
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        if(k>len) return head;
        int Grps = len/k;
        ListNode* groupHead = NULL; 
        ListNode* groupTail = head;
        ListNode* nextgroupHead = NULL;
        ListNode* reversedTail = NULL;
        reverse(head,k, groupHead,nextgroupHead, groupTail);
        ListNode* newHead = groupHead;
        for(int i = 2; i <= Grps; i++){
            ListNode* previousgrpTail = groupTail;
            reverse(nextgroupHead,k, groupHead,nextgroupHead, groupTail);
            previousgrpTail->next = groupHead; 
        }
        if(nextgroupHead) groupTail->next = nextgroupHead; 
        return newHead;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = convertArraytoLL(arr);
    Solution sol;
    int k = 3;
    ListNode* newHead = sol.reverseKGroup(head, k);
    ListNode* temp = newHead;
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}