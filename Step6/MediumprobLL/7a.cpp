#include<bits/stdc++.h>
using namespace std;
// Deleting the kth element of a linked list
// Converting Array to Linked List
struct Node{
    int data;
    Node* next; 
   

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1; 
        next = next1; 
        
    }
    Node(int data1){
        data = data1; 
        next = nullptr; 
        
    }
};
Node* convertArraytoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* reverse(Node* head)
{
    Node* prev = NULL; 
    Node* temp = head; 
    while(temp != NULL)
    {
        Node* front = temp->next; 
        temp->next = prev; 
        prev = temp; 
        temp = front; 
    }
    return prev; 
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;
    Node* slow = head; 
    Node* fast = head; 
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL )
    {
        slow = slow->next; 
        fast = fast->next->next; 
    }
    Node* start = head;
    slow->next = reverse(slow->next);
    Node* sec_half = slow->next;
     Node* check = sec_half; 
    while(sec_half != NULL)
    {
        if(start->data != sec_half->data)
        {
            reverse(check);
            return false; 
        } 
        start = start->next; 
        sec_half = sec_half->next;
    }
    reverse(check);
    return true;
}

// void print(Node* head){
//     while (head != NULL) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

int main()
{
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    Node* head = convertArraytoLL(arr);
    bool ans =  isPalindrome(head);
    cout << ans << endl;
    // print(head);
    return 0; 
}