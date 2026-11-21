#include<bits/stdc++.h>
using namespace std; 
// Converting Array to Linked List
// Deleting the tail of a linked list

struct Node{
    public:
    int data; 
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* convertArrayToLL(vector<int> & arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover-> next = temp;
        mover = temp;
    }
    return head;
}

Node* removedTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL; // If the list is empty or has only one node
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next; // Move to the second last node
    }
    delete temp->next; // Delete the last node
    temp->next = NULL; // Set the next of the second last node to NULL
    return head; // Return the modified list
}

Node* print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {12,5,8,9};
    Node* head = convertArrayToLL(arr);
    head = removedTail(head);
    print(head); // Function to print the linked list
    return 0;
}