#include<bits/stdc++.h>
using namespace std;

// Deleting teh head of a linked list
// Converting Array to Linked List
struct Node{
    public:
    int data; 
    Node* next;

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
 
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int> &arr){
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

Node* removedHead(Node* head)
{
    if(head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next; // Move head to the next node
    delete temp; //It helps to free the memory space of the removed node
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {12,5,8,7};
    Node* head = convertArrayToLL(arr);
    head = removedHead(head);
    print(head);
    return 0;
}