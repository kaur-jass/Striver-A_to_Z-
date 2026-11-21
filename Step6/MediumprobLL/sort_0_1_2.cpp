#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* dummy_0 = new Node(-1); 
        Node* dummy_1 = new Node(-1);
        Node* dummy_2 = new Node(-1);
        Node* z = dummy_0; 
        Node* o = dummy_1; 
        Node* t = dummy_2; 
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == 0){
                z->next = temp;
                z = z->next; 
            }
            else if(temp->data == 1){
                o->next = temp; 
                o = o->next; 
            }
            else if(temp->data == 2){
                t->next = temp;
                t = t->next; 
            }
            temp = temp->next; 
        }
        z->next = (dummy_1->next != nullptr) ? dummy_1->next : dummy_2->next;
        o->next = dummy_2->next;
        t->next = nullptr;
        Node* NewNode = dummy_0->next; 
        delete(dummy_0); 
        delete(dummy_1); 
        delete(dummy_2); 
        return NewNode; 
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0}; 
    Node* head = new Node(arr[0]); 
    Node* mover = head;
    // Conversion of array to linked list
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]); 
        mover->next = newNode;
        mover = newNode; 
    }
    Solution sol; 
    head = sol.segregate(head);
    // Print the sorted linked list
    cout << "Sorted linked list: ";
    mover = head; 
    while(mover != nullptr){
        cout << mover->data << " -> "; 
        mover = mover->next;
    }
    cout << "nullptr" << endl;
    return 0;
}