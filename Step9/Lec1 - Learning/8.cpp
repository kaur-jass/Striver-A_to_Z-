#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int n = s.length(); 
    stack<char> st;  
    for(char c : s)
    {
    if(c == '[' || c == '(' || c == '{') 
        st.push(c); 
    else  
    {
        if(st.empty()) return false; 
        if(st.top() == '[' && c == ']' || st.top() == '(' && c == ')' || st.top() == '{' && c == '}')
        st.pop();  
        else return false;            
    }
    }
    return (st.empty()); 
}

int main() {
    string s;
    cout << "Enter string with brackets: ";
    cin >> s;
    if(isValid(s)) cout << "Valid\n";
    else cout << "Invalid\n";
    return 0;
}
