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

void DeletetheNode(Node* temp) {
    Node* prev = temp->back; 
    Node* front = temp->next;
    if(front == nullptr)
    {
        prev->next = nullptr; 
        temp->back = nullptr; // Set the back pointer of the last node to nullptr
        delete temp; // Delete the last node
        return; // Return the modified list
    }
    else {
        prev->next = front; // Set the next of the previous node to the front node
        front->back = prev; // Set the back pointer of the front node to the previous
        temp->next = nullptr; // Disconnect the current node from the list
        temp->back = nullptr; // Disconnect the back pointer of the current node
        delete temp; // Delete the current node
    }
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
    DeletetheNode(head->next->next); // Deleting the 5th element
    print(head);
    return 0; 
}
