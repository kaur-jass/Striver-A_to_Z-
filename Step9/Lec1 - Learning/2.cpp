#include<bits/stdc++.h>
using namespace std;

class MyQueue{
    int start = -1; 
    int end = -1;
    int currsize = 0;
    int *q_arr; 
    int siz;
    public:
        MyQueue(int s){
            siz = s;
            q_arr = new int[siz]; 
        }
        // Push element to the back of the queue - 0(n)
        void push(int x){
            if(currsize == siz){
                cout << "Queue Overflow\n";
                return;
            }
            if(currsize == 0) {
                start = 0; 
                end = 0; 
            }
            else {
                end = (end + 1) % siz;
            } 
            q_arr[end] = x;
            currsize++;
        }
        // Remove and return the element from the front of the queue - 0(n)
        int pop(){
            if(currsize == 0){
                cout << "Queue Underflow\n";
                return -1; // Return an invalid value
            }
            int element = q_arr[start];
            if(currsize == 1) {
                start = -1; 
                end = -1; 
                currsize--;
            }
            else {
                start = (start + 1) % siz;
                currsize--;
            }
            return element;
        }
        // top  - o(1)
        int top() {
            if(currsize == 0) {
                cout << "Queue is empty\n";
                return -1; // Return an invalid value
            }
            return q_arr[start];
        }
        // Size - o(1)
        int size() {
            return currsize;
        }
}; 

int main() {
    MyQueue q(5);  // Create queue object with size 5
    
    cout << "Pushing elements 10, 20, 30 into queue...\n";
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Top element: " << q.top() << endl;   // Should be 10
    cout << "Popping element: " << q.pop() << endl; // Removes 10
    cout << "Top element after pop: " << q.top() << endl; // Should be 20
    
    cout << "Is queue empty? " << (q.size() == 0 ? "Yes" : "No") << endl;
    
    q.pop();
    q.pop();
    cout << "Is queue empty after popping all? " << (q.size() == 0 ? "Yes" : "No") << endl;
    
    return 0;
}

