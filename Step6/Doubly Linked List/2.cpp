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

Node* Deletehead(Node* head) {
    if (head == nullptr) return nullptr; // If the list is empty, return nullptr
    if(head->next == nullptr) {
        delete head; // If there's only one node, delete it
        return nullptr; // Return nullptr as the new head
    }
    Node * newHead = head;

    head = head->next; // Move the head pointer to the next node
    head->back = nullptr; // Set the back pointer of the new head to nullptr
    newHead->next = nullptr; // Disconnect the old head from the list
    delete newHead; // Delete the old head node
    return head;
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
    head = Deletehead(head); 
    print(head);
    return 0; 
}

