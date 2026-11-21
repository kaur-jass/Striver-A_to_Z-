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
    ListNode* findkthNode(ListNode* temp, int k){
        k-=1;
        while(temp != NULL && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    void reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next; 
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* kthNode = findkthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
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