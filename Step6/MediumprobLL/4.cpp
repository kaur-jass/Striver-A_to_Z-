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
bool hasCycle(Node *head) {
    if(head == NULL || head->next == NULL) return false; 
    Node* temp = head; 
    unordered_set<Node*> visited; 
    while(temp != NULL)
    {
        if(visited.count(temp)) return true;
        visited.insert(temp);
        temp = temp->next;
    }
    return false;  
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
    bool ans =  hasCycle(head);
    cout << ans << endl;
    // print(head);
    return 0; 
}
