#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2) {
        val = data1;
        next = next1;
        child = next2;
    }
};

class Solution {
public:
    ListNode* flattenLinkedList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> vals;
        ListNode* temp = head;
        while(temp != NULL){
            vals.push_back(temp->val);
            ListNode* childTemp = temp->child;
            while(childTemp != NULL){
                vals.push_back(childTemp->val);
                childTemp = childTemp->child;
            }
            temp = temp->next;
        }
        sort(vals.begin(), vals.end());
        if(vals.size() == 0) return NULL;
        ListNode dummy(-1);
        ListNode* ans = &dummy;
        for(int v : vals){
            ans->child = new ListNode(v);
            ans = ans->child;
        }
        return  dummy.child;
    }    
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head->child != nullptr) {
        cout << head->val << " -> ";
        head = head->child;
    }
    cout << head->val;
    cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Creating an instance of Solution class
    Solution sol;
    
    // Function call to flatten the linked list
    ListNode* flattened = sol.flattenLinkedList(head);
    
    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}