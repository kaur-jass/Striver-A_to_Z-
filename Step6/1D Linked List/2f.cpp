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
Node* insert_position(Node* head, int val, int k)
{
    if(head == NULL) 
    {
        if(k == 1) {
            return new Node(val);
        } else {
            return head; // If k is not 1, return head as it is 
        }
    }
    if(k == 1){
        return new Node(val, head);
    }
    int cnt = 0; 
    Node* temp = head;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k-1)
        {
            Node* x = new Node(val, temp->next);
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
    head = insert_position(head,100,3);
    cout << "Linked List after inserting the  new head is : ";
    print(head);
    return 0;
}