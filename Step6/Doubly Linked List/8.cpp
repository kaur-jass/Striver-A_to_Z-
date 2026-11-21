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
Node* Insertbeforek(Node* head, int data, int k)
{
    if (head == nullptr)
    {
        Node* tail = new Node(data, nullptr, nullptr);
        return tail; 
    }
    if(head->next == nullptr && k == 1)
    {
        Node* newNode = new Node(data, head, nullptr);
        head->back = newNode; // Set the back pointer of the old head to the new node
        return newNode; // Return the new head
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp != nullptr)
    {
        cnt++; 
        if(cnt == k)
        {
            Node* newNode = new Node(data, temp, prev);
            temp->back = newNode;
            prev->next = newNode; // Set the next pointer of the previous node to the new node
            return head; // Return the modified list
        }
        prev = temp; 
        temp = temp->next;
    }
    
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
    head = Insertbeforek(head, 7, 5);
    print(head);
    return 0; 
}