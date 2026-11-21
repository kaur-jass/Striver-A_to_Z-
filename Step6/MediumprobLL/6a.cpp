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

int length_of_cycle(Node *head) {
    if (head == NULL || head->next == NULL) return 0;

    Node* temp = head;
    int timer = 1; 
    map<Node*, int> mpp; 
    while(temp != NULL)
    {
        auto it = mpp.find(temp); 
        if(it != mpp.end()){
            int value = mpp[temp]; 
            return timer-value; 
        }
        mpp[temp] = timer; 
        timer++; 
        temp = temp->next;
    }
    return 0; 
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
    int ans =  length_of_cycle(head);
    cout << ans << endl;
    // print(head);
    return 0; 
}
