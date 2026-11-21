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
        Node* temp = head;
        unordered_map<Node*, Node*> mp;
        while(temp != NULL){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
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