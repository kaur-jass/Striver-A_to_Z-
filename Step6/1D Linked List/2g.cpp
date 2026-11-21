#include<bits/stdc++.h>
using namespace std;

// Deleting the kth element of a linked list
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
    Node(int data1){
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
Node* insert_before_value(Node* head, int el, int val)
{
    if(head == NULL) 
    {
        return NULL;
    }
    if(head->data == val) {
        return new Node(el, head);
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->next->data == val)
        {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
  
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
    head = insert_before_value(head,100,7);
    cout << "Linked List after inserting the  new head is : ";
    print(head);
    return 0;
}