#include<bits/stdc++.h>
using namespace std; 

class Node{
    public:
        int data;
        Node* next; 
        Node(int data1, Node* next1){
            data = data1; 
            next = next1; 
        }
        int getData(){
            return data; 
        }
        Node* getNext(){
            return next; 
        }
}; 

class Solution{
    public:
        
    Node* inserthead(Node* head, int val){
        Node* newNode = new Node(val, head);
        if(head == nullptr) return newNode;
        return newNode;
    }
    Node* insertTail(Node* head, int val){
        Node* newNode = new Node(val, nullptr);
        if(head == nullptr) return newNode;
        Node* temp = head; 
        while(temp->next != nullptr){
            temp = temp->next; 
        }
        temp->next = newNode;
        return head;
    }
    Node* insertk(Node* head, int k, int val){
        Node* newNode = new Node(val, nullptr);
        if(head == nullptr) return newNode;
        Node* temp = head;
        if(k == 1){
            newNode->next = head; 
            return newNode; 
        }
        while(k>2 && temp != nullptr){
            temp = temp->next; 
            k--; 
        }
        if(temp == nullptr) return head;
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    Node* insert_before_value(Node* head, int x, int val){
        Node* newNode = new Node(val, nullptr);
        if(head == nullptr) return newNode;
        if(head->data == x){
            newNode->next = head; 
            return newNode; 
        }
        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != x){
            temp = temp->next; 
        }
        if(temp->next == nullptr) return head;
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    void printLinkedList(Node* head){
        Node* mover = head; 
        cout << "Linked list: ";
        while(mover->next != nullptr){
            cout << mover->data << " -> "; 
            mover = mover->next;
        }
        cout << mover->data; 
        cout << endl;     
    }
};

// Driver Code
int main(){
    vector<int> arr = {2,5,8,7, 10, 15}; 
    Node* head = new Node(arr[0], nullptr); 
    Node* mover = head;
    //Conversion of array to linked list
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr); 
        mover->next = newNode;
        mover = newNode; 
    }
    // Now i will do different operations on the linked list.

    // 1. Traversal of the linked list
    //Print the linked list
    mover = head; 
    cout << "Linked list: ";
    while(mover->next != nullptr){
        cout << mover->data << " -> "; 
        mover = mover->next;
    }
    cout << mover->data; 
    cout << endl;

    // 2. Deletion of a head from the linked list
    Solution sol;
    head = sol.inserthead(head, 1);
    cout << "After insertion of head : " << endl; 
    sol.printLinkedList(head);

    //3. Deletion of a tail form the linked list 
    Solution sol2;
    head = sol2.insertTail(head, 9);
    cout << "After insertion of tail: " << endl; 
    sol2.printLinkedList(head);

    //4. Deletion of Kth element of Linked List 
    Solution sol3;
    head = sol3.insertk(head, 3, 82);
    cout << "After insertion of kth Element " << endl; 
    sol3.printLinkedList(head);

    //5. Deletion of element with value x; 
    Solution sol4;
    head = sol4.insert_before_value(head, 8, 80);
    cout << "Before element with Value X = 8 " << endl; 
    sol4.printLinkedList(head);

    //6. Length of linked list
    int length = 0;
    mover = head;
    while(mover != nullptr){
        length++; 
        mover = mover->next; 
    }
    cout << "Length of linked list is: " << length << endl;

    // 7. Searching for an element in the linked list
    int searchValue = 10;
    mover = head;
    bool found = false;
    while(mover != nullptr){
        if(mover->data == searchValue){
            found = true; 
            break; 
        }
        mover = mover->next; 
    }
    if(found){
        cout << "Element " << searchValue << " found in the linked list." << endl;
    }
    else{
        cout << "Element " << searchValue << " not found in the linked list." << endl;
    }

    return 0; 
}