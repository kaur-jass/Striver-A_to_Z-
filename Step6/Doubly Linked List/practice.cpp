#include<bits/stdc++.h>
using namespace std; 

struct Node{
    public:
        int data; 
        Node* next; 
        Node* back; 
        Node(int val) : data(val), next(nullptr), back(nullptr) {}
        Node(int val, Node* nextNode, Node* backNode) : data(val), next(nextNode), back(backNode) {}
}; 

class Del_Solution{
    public:
        void print(Node* head){
            Node* temp = head;
            if(temp == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            while(temp->next!= nullptr){
                cout << temp->data << "->"; 
                temp = temp->next; 
            }
            cout << temp->data << endl; 
        }

        void deletehead(Node* &head){
            if(head == nullptr || head->next == nullptr) {
                cout << "List is empty or has only one node, cannot delete head." << endl;
                return;
            }
            Node* temp = head; 
            head = head->next; 
            temp->next = nullptr; 
            delete(temp); 
            cout << "The head node has been deleted." << endl;
            print(head);
        }
        void deletetail(Node* &head){
            if(head == nullptr || head->next == nullptr) {
                cout << "List is empty or has only one node, cannot delete tail." << endl;
                return;
            }
            Node* temp = head; 
            while(temp->next->next != nullptr){
                temp = temp->next; 
            }
            Node* tail = temp->next;
            temp->next = nullptr;
            delete(tail);
            cout << "The tail node has been deleted." << endl;
            print(head);
        }
        void deletekth(Node* &head, int k){
            if(head == nullptr || head->next == nullptr) {
                cout << "List is empty or has only one node, cannot delete kth node." << endl;
                return;
            }
            Node* temp = head; 
            for(int i = 1; i < k-1 && temp != nullptr; i++){
                temp = temp->next; 
            }
            if(temp == nullptr || temp->next == nullptr) {
                cout << "The kth node does not exist." << endl;
                return;
            }
            Node* kthNode = temp->next; 
            temp->next = kthNode->next; 
            if(kthNode->next != nullptr) {
                kthNode->next->back = temp; 
            }
            delete(kthNode); 
            cout << "The " << k << "the node has been deleted." << endl;
            print(head);
        }
        void deletevalue(Node* head, int val){
            if(head == nullptr){
                cout << "List is empty, cannot delete value." << endl;
                return;
            }
            Node* temp = head; 
            while(temp != nullptr && temp->data != val){
                temp = temp->next; 
            }
            if(temp == nullptr) {
                cout << "The value " << val << " does not exist in the list." << endl;
                return;
            }
            Node* prevNode = temp->back;
            Node* nextNode = temp->next;
            if(prevNode != nullptr) { // FOR THE FIRST NODE, prevNode will be nullptr
                prevNode->next = nextNode; 
            } else {
                head = nextNode; // Update head if the first node is deleted
            }
            if(nextNode != nullptr) {
                nextNode->back = prevNode; 
            }
            delete(temp);
            cout << "The node with value " << val << " has been deleted." << endl;
            print(head);
        }
}; 

class Ins_Solution{
    public:
        void print(Node* head){
            Node* temp = head;
            if(temp == nullptr){
                cout << "List is empty" << endl;
                return;
            }
            while(temp->next!= nullptr){
                cout << temp->data << "->"; 
                temp = temp->next; 
            }
            cout << temp->data << endl; 
        }

        void inserthead(Node* &head, int val){
            Node* newNode = new Node(val, head, nullptr); 
            if(head != nullptr) {
                head->back = newNode; 
            }
            head = newNode;
            cout << "The new head node with value " << val << " has been inserted." << endl;
            print(head);
        }
        void insertbeftail(Node* &head, int val){
            if(head == nullptr) {
                cout << "The list is empty, cannot insert before tail." << endl;
                return;
            }
            if (head->next == nullptr) {
                cout << "Only one node exists. Cannot insert before tail." << endl;
                return;
            }
            Node* temp = head; 
            while(temp->next->next != nullptr){
                temp = temp->next; 
            }
            if(temp->next == nullptr) {
                cout << "The list has only one node, cannot insert before tail." << endl;
                return;
            }
            Node* newNode = new Node(val, temp->next, temp);
            temp->next->back = newNode; // Update the back pointer of the tail node
            temp->next = newNode; // Update the next pointer of the node before tail
            cout << "The new node with value " << val << " has been inserted before the tail." << endl;
            print(head);
        }
        void insertk(Node* &head, int k, int val){
            if(head == nullptr) {
                cout << "The list is empty, cannot insert before kth node." << endl;
                return;
            }
            Node* temp = head; 
            for(int i = 1; i < k-1 && temp != nullptr; i++){
                temp = temp->next; 
            }
            if(temp == nullptr || temp->next == nullptr) {
                cout << "The kth node does not exist, cannot insert before it." << endl;
                return;
            }
            Node*newNode = new Node(val, temp->next, temp);
            temp->next->back = newNode; 
            temp->next = newNode;
            cout << "The new node with value " << val << " has been inserted before the " << k << "th node." << endl;
            print(head);
        }
        void insert_val(Node* &head, int targetVal, int val){
            if(head == nullptr) {
                cout << "The list is empty, cannot insert before the node with value " << targetVal << "." << endl;
                return;
            }
            Node* temp = head; 
            while(temp != nullptr && temp->data != targetVal){
                temp = temp->next; 
            }
            if(temp == nullptr) {
                cout << "The node with value " << targetVal << " does not exist, cannot insert before it." << endl;
                return;
            }
            Node* newNode = new Node(val, temp, temp->back);
            if(temp->back != nullptr) {
                temp->back->next = newNode; 
            } else {
                head = newNode; // Update head if inserting before the first node
            }
            temp->back = newNode; 
            cout << "The new node with value " << val << " has been inserted before the node with value " << targetVal << "." << endl;
            print(head);
        }
};

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 9, 38, 90, 92, 100}; 
    Node* head = new Node(arr[0]); 
    Node* prev = head;
    //Convert array to To doubly Linked List; 
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev); 
        prev->next = temp; 
        prev = temp;
    }
    // 1. Print the linked list
    Del_Solution sol;
    cout << "The doubly linked list is: ";
    sol.print(head);

    // 2. Delete in the doubly Linked List 
    // - head, tail, kth, node with value
    Del_Solution sol1;
    sol1.deletehead(head);
    sol1.deletetail(head);
    sol1.deletekth(head, 2);
    sol1.deletevalue(head, 4);


    // Lets start with Insertion Now; 
    // Print the linked list
    Ins_Solution sol2;
    cout << "The doubly linked list is: ";
    sol2.print(head);
    // 1.Insert the head before the head node;
    sol2.inserthead(head, 0);
    //2. Insert Node Before tail Node; 
    sol2.insertbeftail(head, 99);
    // 3. Insert Node before the kth Node;
    sol2.insertk(head, 7, 7); // Assuming you want to insert before the 7th node the node with value 7
    // 4. Insert before given node with value;
    sol2.insert_val(head, 9, 8); // Assuming you want to insert before the node with value 9 the node with value 8


    // Last Practice  - reverse a doubly linked list;
    Node* current = head; 
    Node* prevNode = nullptr;
    while(current != nullptr){
        Node* nextNode = current->next; 
        current->next = prevNode; 
        current->back = nextNode; 
        prevNode = current; 
        current = nextNode; 
    }
    head = prevNode;
    sol2.print(head); // Print the reversed list
    return 0; 
}