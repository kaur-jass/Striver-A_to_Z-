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
    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next; 
    }
    Node* prev = tail->back; // Get the second last node
    prev->next = nullptr; // Set the next of the second last node to NULL
    tail->back = nullptr; // Set the back pointer of the last node to nullptr
    delete tail; // Delete the last node
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
