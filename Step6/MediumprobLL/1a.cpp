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

Node* middle_element(Node*& head) {
    if(head == nullptr) return nullptr; // Check if the list is empty
    if(head->next == nullptr) return head; // If there's only one element, return it
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow by one step
        fast = fast->next->next; // Move fast by two steps
    }
    return slow; // Slow will be at the middle element when fast reaches the end
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
    Node* head = convertArrayToLL(arr);
    Node* middle = middle_element(head);
    cout << "Middle Element: " << (middle ? middle->data : -1) << endl; // Print middle element
    return 0; 
}
