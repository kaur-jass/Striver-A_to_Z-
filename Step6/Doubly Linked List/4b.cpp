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

Node* Deletek(Node* head, int k) {
    if (head == nullptr) return nullptr; // If the list is empty, return nullptr
    if (head->next == nullptr) 
    {
        delete head; // If the list only has one element
        return nullptr; // If the list only has one elemenail    
    }
    Node* temp = head;
    int cnt = 0; 
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break; 
        temp = temp->next; 
        
    }
    Node* prev = temp->back; // Get the previous node
    Node* front = temp->next; 
    if(prev == nullptr && front == nullptr) // If the list only has one element
    {
        delete head; // Delete the head node
        return nullptr; // Return nullptr
    }
    else if(front == nullptr) // If we are deleting the last element
    {
        prev->next = nullptr; // Set the next of the previous node to nullptr
        delete temp; // Delete the last node
        return head; // Return the modified list
    }
    else if( prev == nullptr)
    {
        front->back = nullptr; // Set the back pointer of the front node to nullptr
        head = front; // Move the head pointer to the front node
        delete temp; // Delete the old head node
        return head; // Return the new head
    }
    prev->next = front;
    front->back = prev; // Set the back pointer of the front node to the previous node
    delete temp; // Delete the kth node
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
    head = Deletek(head, 3); // Deleting the 5th element
    print(head);
    return 0; 
}
