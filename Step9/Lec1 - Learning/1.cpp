#include<bits/stdc++.h>
using namespace std;

// Implementing Stack using Arrays 
class Stack {
    int stackTop;
    int siz;
    int* arr;
    public:
        Stack(int s) {
            siz = s;
            stackTop = -1;
            arr = new int[s];
        }
        ~Stack() {
            delete[] arr;
        }
        void push(int x){
            if(stackTop == siz - 1) {
                cout << "Stack Overflow\n";
                return;
            }
            arr[++stackTop] = x;
        }
        int top() {
            if(stackTop == -1) {
                cout << "Stack is empty\n";
                return -1; // Return an invalid value
            }
            return arr[stackTop];
        }
        int pop() {
            if(stackTop == -1) {
                cout << "Stack Underflow\n";
                return -1; // Return an invalid value
            }
            return arr[stackTop--];
        }
        bool empty() {
            return stackTop == -1;
        }
        int size() {
            return stackTop + 1;
        }
};


int main() {
    Stack st(10);  // Create stack object with size 5
    
    cout << "Pushing elements 10, 20, 30 into stack...\n";
    st.push(10);
    st.push(20);
    st.push(30);
    
    cout << "Top element: " << st.top() << endl;   // Should be 30
    cout << "Popping element: " << st.pop() << endl; // Removes 30
    cout << "Top element after pop: " << st.top() << endl; // Should be 20
    
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    
    st.pop();
    st.pop();
    cout << "Is stack empty after popping all? " << (st.empty() ? "Yes" : "No") << endl;
    
    return 0;
}