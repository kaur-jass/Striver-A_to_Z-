#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list:
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                tail->child = l1;
                l1 = l1->child;
            } else {
                tail->child = l2;
                l2 = l2->child;
            }
            tail = tail->child;
            tail->next = NULL;
        }

        if(l1 != NULL) tail->child = l1;
        if(l2 != NULL) tail->child = l2;
        return dummy->child;
    }
    ListNode* flattenLinkedList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mergedHead = flattenLinkedList(head->next);
        return merge(head, mergedHead);
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
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
    ListNode* head = new ListNode(3);

    head->next = new ListNode(2);
    head->next->child = new ListNode(10);

    head->next->next = new ListNode(1);
    head->next->next->child = new ListNode(7);
    head->next->next->child->child = new ListNode(11);
    head->next->next->child->child->child = new ListNode(12);

    head->next->next->next = new ListNode(4);
    head->next->next->next->child = new ListNode(9);

    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->child = new ListNode(6);
    head->next->next->next->next->child->child = new ListNode(8);


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