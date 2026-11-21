#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val; 
    ListNode* next; 
    ListNode* prev; 
    public:
    ListNode(int data1, ListNode* next1, ListNode* prev1){
        val = data1; 
        next = next1; 
        prev = prev1; 
    }
    ListNode(int data1){
        val = data1; 
        next = nullptr; 
        prev = nullptr; 
    }
};
ListNode* convertArraytoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;
    for(int i = 1; i < arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i], nullptr, prev); 
        prev->next = temp; 
        prev = temp;
    }
    return head;
}

ListNode* deleteAllOccurences(ListNode* head, int k){
    if(!head) return NULL;
    if(head->next == NULL && head->val == k) return NULL;
    
    while(head && head->val == k){
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL; 
        if(head) head->prev = NULL;;
        delete(temp);
    }
    ListNode* temp = head; 
    while(temp != NULL){
        if(temp->val == k){
            ListNode* del = temp;
            ListNode* prev = temp->prev;
            ListNode* nex = temp->next;
            if(prev) prev->next = nex;
            if(nex) nex->prev = prev;
            temp = nex;
            del->next = NULL;
            del->prev = NULL;
            delete(del);
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}



int main()
{
    vector<int> arr = {10,10,4,10,6,10};
    ListNode* head = convertArraytoLL(arr);
    // Print the linked list
    ListNode* temp = deleteAllOccurences(head, 10);
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}