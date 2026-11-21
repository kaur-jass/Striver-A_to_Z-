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
Node* oddEvenList(Node* head) {
    if(head == NULL || head->next == NULL) return head; 
    Node* odd = head; 
    Node* evenHead = head->next; 
    Node* even = head->next; 
    while(even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next; 
        odd = odd->next; 
        even->next = even->next->next; 
        even = even->next; 
    }
    odd->next = evenHead; 
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
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    Node* head = convertArraytoLL(arr);
    oddEvenList(head);
    print(head);
    return 0; 
}