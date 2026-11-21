#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> s;
    long long mini; 
    MinStack(){
        mini = LLONG_MAX;  
    }
    
    void push(int val) {
        if (s.empty()) {
            mini = val; 
            s.push(val); 
        }
        else if(val >= mini) {
            s.push(val); 
        }
        else {
            s.push(2LL * val - mini);  // store encoded value
            mini = val; 
        }
    }
    
    void pop() {
       if(s.empty()) return; 
       long long x = s.top(); 
       s.pop(); 
       if(x < mini) { // encoded value
           mini = 2LL * mini - x; 
       }
    }
    
    int top() {
        if(s.empty()) return 0; 
        long long x = s.top(); 
        if (x >= mini) return (int)x;  // normal value
        else return (int)mini;         // encoded value
    }
    
    int getMin() {
        return (int)mini; 
    }
};

int main() {
    MinStack st;

    cout << "Pushing values: 5, 3, 7, 2\n";
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Current Min: " << st.getMin() << "\n";  // expect 2
    cout << "Top: " << st.top() << "\n";             // expect 2

    st.pop();
    cout << "After popping, Min: " << st.getMin() << "\n"; // expect 3
    cout << "Top: " << st.top() << "\n";                   // expect 7

    st.pop();
    cout << "After popping again, Min: " << st.getMin() << "\n"; // expect 3
    cout << "Top: " << st.top() << "\n";                         // expect 3

    return 0;
}
