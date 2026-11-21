//You are given a stack of integers.
// Your task is to reverse the stack using recursion. 
// You may only use standard stack operations (push, pop, top/peek, isEmpty).
// You are not allowed to use any loop constructs or additional data structures like arrays or queues.

#include <bits/stdc++.h>
using namespace std;


// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    // If stack is empty, push the value
    if (st.empty()) {
        st.push(val);
        return;
    }

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recurse for the rest of the stack
    insertAtBottom(st, val);

    // Push the popped element back
    st.push(topVal);
}


void reverseStack(stack<int>& s){
    // Base Case 
    if(s.empty()) return; 
    // Recursive Case
    int topElement = s.top();
    s.pop();
    reverseStack(s);
    // Insert at bottom function
    insertAtBottom(s, topElement);
}
int main() {
    stack<int> st;
    int n, element;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter the elements of the stack (from bottom to top):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        st.push(element);   // push builds stack correctly
    }

    reverseStack(st);

    cout << "Reversed stack (from top to bottom):" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
    return 0;
}
