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
        
    Node* deletehead(Node* head){
        if(head == nullptr || head->next == nullptr) return nullptr; 
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* deleteTail(Node* head){
        if(head == nullptr || head->next == nullptr) return nullptr;
        Node* temp = head; 
        while(temp->next->next != nullptr){
            temp = temp->next; 
        }
        delete(temp->next); 
        temp->next = nullptr; 
        return head; 
    }
    Node* deletek(Node* head, int k){
        if(head == nullptr) return nullptr; 
        Node* temp = head; 
        Node* prev = nullptr;
        //edge cases 
        if(k == 1) {
            head = head->next;
            delete temp;
            return head;
        } 
        while(k>1 && temp != nullptr){
            prev = temp; 
            temp = temp->next;
            k--; 
        }
        if(temp == nullptr) return head;
        prev->next = temp->next; 
        delete(temp); 
        return head; 
    }

    Node* del_with_value(Node* head, int val){
        if(head == nullptr) return head; 
        Node* mover = head; 
        Node* prev = nullptr; 
        if(head ->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head; 
        }
        while(mover != nullptr && mover->data != val){
            prev = mover; 
            mover = mover->next; 
        }
        if(mover == nullptr) return head; 
        prev->next = mover->next; 
        delete(mover); 
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
    head = sol.deletehead(head);
    cout << "After deletion of head : " << endl; 
    sol.printLinkedList(head);

    //3. Deletion of a tail form the linked list 
    Solution sol2;
    head = sol2.deleteTail(head);
    cout << "After deletion of tail: " << endl; 
    sol2.printLinkedList(head);

    //4. Deletion of Kth element of Linked List 
    Solution sol3;
    head = sol3.deletek(head, 3);
    cout << "After deletion of kth Element " << endl; 
    sol3.printLinkedList(head);

    //5. Deletion of element with value x; 
    Solution sol4;
    head = sol4.del_with_value(head, 8);
    cout << "After deletion of Element with Value X = 8 " << endl; 
    sol4.printLinkedList(head);

    return 0; 
}