#include<bits/stdc++.h>
using namespace std;

string prefix_to_postfix(string s) {
    stack<string> st; 
    int n = s.length(); 
    for(int i = n-1; i >= 0; i--) {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            string op(1, s[i]); 
            st.push(op); 
        }
        else { // Operator
            string op1 = st.top(); 
            st.pop(); 
            string op2 = st.top(); 
            st.pop(); 
            string temp = op1 + op2 + s[i]; 
            st.push(temp); 
        }
    }
    return st.top(); 
};

int main() {
    string s; 
    cout << "Enter prefix expression: ";
    cin >> s; 
    cout << "Postfix expression: " << prefix_to_postfix(s) << endl;
}