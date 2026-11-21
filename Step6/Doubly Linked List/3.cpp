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

Node* Deletetail(Node* head) {
    if (head == nullptr) return nullptr; // If the list is empty, return nullptr
    if (head->next == nullptr) 
    {
        delete head; // If the list only has one element
        return nullptr; // If the list only has one elemenail    
    }
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next; // Move to the second last node
    }
    temp->next->back = nullptr;
    delete temp->next; // Delete the last node
    temp->next = nullptr; // Set the next of the second last node to NULL
    return head; // Return the modified list    
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
    head = Deletetail(head); 
    print(head);
    return 0; 
}
