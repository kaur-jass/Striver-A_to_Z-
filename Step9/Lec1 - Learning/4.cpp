#include <iostream>
#include <stack>
using namespace std;

// class MyQueue {
// public:
//     stack<int> s1; 
//     stack<int> s2; 

//     MyQueue() {
//     }
    
//     void push(int x) {
//         s1.push(x);  
//     }
    
//     int pop() {
//         if(s2.empty()) {
//             while(!s1.empty()) {
//                 s2.push(s1.top()); 
//                 s1.pop();
//             } 
//         }  
//         int val = s2.top();
//         s2.pop(); 
//         return val;      
//     }
    
//     int peek() {
//         if(s2.empty()) {
//             while(!s1.empty()) {
//                 s2.push(s1.top()); 
//                 s1.pop();
//             }
//         }
//         return s2.top();
//     }
    
//     bool empty() {
//         return s1.empty() && s2.empty(); 
//     }
// };

class MyQueue {
    // Approach1: Using two Stacks and 0(2n) time complexity for push op 
public:
    stack<int> s1; 
    stack<int> s2; 

    MyQueue() {
    }
    
    void push(int x) {
        if (!s1.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top()); 
                s1.pop();
            } 
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top()); 
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop(); 
        return val;   
    }
    
    int peek() {
        return s1.top();
    }
    
    int size() {
        return s1.size() + s2.size();
    }

    bool empty() {
        return s1.empty() && s2.empty(); 
    }
};

int main() {
    MyQueue q;  // create queue object

    cout << "Pushing 10, 20, 30 into queue...\n";
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;   // should be 10
    cout << "Popping element: " << q.pop() << endl;  // removes 10
    cout << "Front element after pop: " << q.peek() << endl; // should be 20

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop(); // removes 20
    q.pop(); // removes 30
    cout << "Is queue empty after popping all? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
