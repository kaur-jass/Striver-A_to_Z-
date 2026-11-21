#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int n = s.size();
    string result = ""; 
    int depth = 0; 
    for(int i = 0; i<n; i++)
    {    
        if(s[i] == '(')  
        {
            depth++;
            if(depth == 1) continue;
            result += s[i];
        }    
        else if(s[i] == ')') 
        {
            depth--; 
            if(depth == 0) 
            {
                continue;
            }
            result += s[i];
        }
    }
    return result;
}

int main()
{
    string s;
    getline(cin,s);
    cout << removeOuterParentheses(s) << endl;
    return 0; 
}