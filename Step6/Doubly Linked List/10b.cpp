#include<bits/stdc++.h>
using namespace std;
// Deleting the kth element of a linked list
// Converting Array to Linked List
struct Node{
    int data;
    Node* next; 
    Node* back; 

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1; 
        next = next1; 
        back = back1; 
    }
    Node(int data1){
        data = data1; 
        next = nullptr; 
        back = nullptr; 
    }
};
Node* convertArraytoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head; 
    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev); 
        prev->next = temp; 
        prev = temp;
    }
    return head; 
}

void reverse(Node*& head) {
    Node* last = nullptr; 
    Node* current = head;
    if(head == nullptr || head->next == nullptr) return; // No need to reverse if list is empty or has one element
    while (current != nullptr) 
    {
        last = current->back; 
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    if(last != nullptr) 
       head = last->back; // Update head to the new first element
}    
void print(Node* head){
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArraytoLL(arr);
    reverse(head);
    print(head);
    return 0; 
}
