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
Node* removedk(Node* head, int k)
{
    if(head == NULL) return head; 
    if(k == 1){
        Node* temp = head; 
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0; 
    Node* temp = head; 
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp; 
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
    head = removedk(head, 2); // Remove the 2nd element
    cout << "Linked List after removing the 2nd element: ";
    print(head);
    return 0;
}