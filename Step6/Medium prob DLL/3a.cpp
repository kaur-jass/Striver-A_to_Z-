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

ListNode* deleteduplicates(ListNode* head){
    if(!head) return NULL;
    if(!head->next) return head;
    ListNode* temp = head; 
    while(temp != NULL && temp->next != NULL){
        ListNode* nextNode = temp->next;
        while(nextNode != NULL && temp->val == nextNode->val){
            ListNode* del = nextNode;
            nextNode = nextNode->next;
            delete(del);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;     
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,1,1,3,3,4,5};
    ListNode* head = convertArraytoLL(arr);
    // Print the linked list
    ListNode* temp = deleteduplicates(head);
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}