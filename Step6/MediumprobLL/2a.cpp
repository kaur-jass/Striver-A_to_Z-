#include<bits/stdc++.h>
using namespace std;
// Deleting the kth element of a linked list
// Converting Array to Linked List
struct Node{
    int data;
    Node* next; 
   

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1; 
        next = next1; 
        
    }
    Node(int data1){
        data = data1; 
        next = nullptr; 
        
    }
};
Node* convertArraytoLL(vector<int> &arr){
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

Node* reverse_single_ll(Node*& head) {
    Node* temp = head; 
    stack<int> st;
    while(temp != NULL)
    {
        st.push(temp->data); 
        temp = temp->next; 
    }
    temp = head;
    while(temp != NULL)
    {
        temp->data = st.top(); 
        st.pop();
        temp = temp->next; 
    }
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
    head = reverse_single_ll(head);
    print(head);
    return 0; 
}
