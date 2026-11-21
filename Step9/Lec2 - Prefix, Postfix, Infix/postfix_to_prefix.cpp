#include<bits/stdc++.h>
using namespace std;

string postfix_to_prefix(string s) {
    stack<string> st; 
    int n = s.length(); 
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            string op(1, s[i]); 
            st.push(op); 
        }
        else { // Operator
            string op2 = st.top(); 
            st.pop(); 
            string op1 = st.top(); 
            st.pop(); 
            string temp = s[i] + op1 + op2; 
            st.push(temp); 
        }
    }
    return st.top(); 
};

int main() {
    string s; 
    cout << "Enter postfix expression: ";
    cin >> s; 
    cout << "Prefix expression: " << postfix_to_prefix(s) << endl;
}