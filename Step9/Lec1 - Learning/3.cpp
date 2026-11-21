#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q; 
    MyStack() {    
    }
    
    void push(int x) {
        int s = q.size(); 
        q.push(x); 
        for(int i = 0; i < s; i++) {
            q.push(q.front()); 
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front(); 
        q.pop();
        return val;
    }
    
    int top() {
        return q.front(); 
    }

    int size() {
        return q.size(); 
    }
    
    bool empty() {
        return q.empty(); 
    }
};

int main() {
    MyStack st;  // Create stack object
    
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Pushing elements 10, 20, 30 into stack...\n";
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout << "Top element: " << st.top() << endl;   // Should be 30
    cout << "Popping element: " << st.pop() << endl; // Removes 30
    cout << "Size of the stack: " << st.size() << endl; // Should be 2
    cout << "Top element after pop: " << st.top() << endl; // Should be 20
    
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    
    st.pop();
    st.pop();
    cout << "Is stack empty after popping all? " << (st.empty() ? "Yes" : "No") << endl;
    
    return 0;
}
