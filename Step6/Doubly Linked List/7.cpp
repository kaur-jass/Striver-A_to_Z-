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

Node* Insertaftertail(Node* head, int data)
{
    if (head == nullptr)
    {
        Node* tail = new Node(data, nullptr, nullptr);
        return tail; 
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node* newTail = new Node(data,nullptr,temp);
    temp->next = newTail;
    return head;
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
    head = Insertaftertail(head, 7);
    print(head);
    return 0; 
}