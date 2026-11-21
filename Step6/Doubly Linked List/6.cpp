#include<bits/stdc++.h>
using namespace std; 
struct Node{
    int data; 
    Node* next; 
    Node* back; 

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1; 
        next = next1; 
        back = back1;
    }
    
    Node(int data1){
        data = data1; 
        next = nullptr;
        back = nullptr;
    }    
};

Node* convertArraytoLL(vector<int> & arr)
{
    if(arr.empty()) return nullptr; 
    Node* head = new Node(arr[0]);
    Node* prev = head; 
    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev); 
        prev->next = temp; 
        prev = temp;
    }
    return head; 
}

Node* Insertathead(Node* head, int data)
{
    if (head == nullptr) return nullptr; 
    Node* newNode = new Node(data, head, nullptr);
    head->back = newNode; // Set the back pointer of the old head to the new node
    return newNode; // Return the new head
}
void print(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArraytoLL(arr);
    head = Insertathead(head, 7);
    print(head);
    return 0; 

}