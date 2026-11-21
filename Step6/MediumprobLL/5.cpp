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

Node *detectCycle(Node *head) {
    Node* temp = head; 
    map<Node*, int> mpp;
    int x = 0; 
    while(temp != NULL)
    {
        auto it = mpp.find(temp);
        if (it != mpp.end()) {
            return temp;
        }
        mpp[temp] = x; 
        x++; 
        temp = temp->next;
    }
    return NULL;
}

// void print(Node* head){
//     while (head != NULL) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArraytoLL(arr);
    Node * ans =  detectCycle(head);
    cout << ans << endl;
    // print(head);
    return 0; 
}
