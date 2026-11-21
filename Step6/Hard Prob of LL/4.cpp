#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1 - Creating a Copy List 
        Node* temp = head; 
        while(temp != NULL){
            Node* next = temp->next; 
            Node* copy = new Node(temp->val); 
            temp->next = copy; 
            copy->next = next; 
            temp = next; 
        }

        // Step 2 - Making the correct Random Pointer 
        Node* ran = head; 
        while(ran != NULL){
            if(ran->random == NULL){
                ran->next->random = NULL;
            }
            else{
                ran->next->random = ran->random->next;    
            }
            ran = ran->next->next;
        }
         
         //Step 3 - Separate the Lists 
        Node* t = head; 
        Node dummy(-1); 
        Node* result = &dummy; 
        while(t != NULL){
            Node* copy = t->next; 
            result->next = copy;
            result = result->next; 

            t->next = copy->next; 
            t = t->next; 
            
        }
        return dummy.next;
    }
};


int main() {
    // Creating a linked list with random pointers
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    // Creating an instance of Solution class
    Solution sol;

    // Function call to copy the linked list
    Node* copiedList = sol.copyRandomList(head);

    // Printing the copied linked list to verify
    Node* temp = copiedList;
    while (temp != nullptr) {
        cout << "Node Value: " << temp->val << ", ";
        if (temp->random) {
            cout << "Random points to: " << temp->random->val << endl;
        } else {
            cout << "Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    return 0;
}