#include<bits/stdc++.h>
using namespace std;

int priority(char c) {
    if(c == '^') return 3; 
    else if(c == '*' || c == '/') return 2; 
    else if(c == '+' || c == '-') return 1; 
    else return -1; 
}
string infixToPostfix(string s) {
    int n = s.length();
    int i = 0;
    stack<char> st; 
    string res = ""; 
    while(i<n) {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            res += s[i]; 
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top(); 
                st.pop(); 
            }
            if(!st.empty()) st.pop(); 
        }
        else { // Operators left 
            while(!st.empty() && (priority(st.top()) >= priority(s[i]))) {
                res += st.top(); 
                st.pop(); 
            }
            st.push(s[i]);
        }
        i++; 
    }
    while(!st.empty()) {
        res += st.top(); 
        st.pop(); 
    }
}; 