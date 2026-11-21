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
    if(k == 1) {
        Node* newHead = head->next; // Move the head pointer to the next node
        newHead->back = nullptr; // Set the back pointer of the new head to nullptr
        delete head; // Delete the old head node
        return newHead; // Return the new head
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0; 
    while(temp->next != nullptr){
        if(cnt == k-1) // If we reach the kth node
        {
            prev->next = temp->next;
            temp->next->back= prev; // Set the back pointer of the next node
            delete temp; // Delete the kth node
            break; // Exit the loop after deletion
        }
        prev = temp; // Store the previous node
        temp = temp->next; // Move to the next node
        cnt++; // Increment the count
    }
    if(temp->next == nullptr && cnt == k-1) {
        // If we reach the end of the list and k is equal to the length of the list
        if(prev != nullptr) {
            prev->next = nullptr; // Set the next of the previous node to nullptr
            temp->back = nullptr; // Set the back pointer of the last node to nullptr
        }
        delete temp; // Delete the last node
    }

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
    head = Deletek(head, 1); 
    print(head);
    return 0; 
}
