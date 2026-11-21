// Problem Statement: You are given a stack of integers.
// Your task is to sort the stack in descending order using recursion, 
// such that the top of the stack contains the greatest element. 
// You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). 
// You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

#include <bits/stdc++.h>
using namespace std;
void sortStack(stack<int>& st) {
    // BASE CASE
    if(st.empty()) return;
    if(st.size() == 1) return;
    // RECURSION
    int topElement = st.top(); 
    st.pop();
    int secondTopElement = st.top();
    st.pop();
    if (topElement < secondTopElement) {
        st.push(secondTopElement);
        sortStack(st);
        st.push(topElement);
    } else {
        st.push(topElement);
        sortStack(st);
        st.push(secondTopElement);
    }
}
int main() {
    stack<int> st; 
    int n, element; 
    cout << "Enter the number of elements in the stack: ";
    cin >> n; 

    cout << "Enter the elements of the stack (from top to bottom):" << endl;
    for(int i = 0; i < n; ++i) {
        cin >> element;
        st.push(element);
    }
    sortStack(st);
    cout << "Sorted stack (from top to bottom):" << endl;
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}