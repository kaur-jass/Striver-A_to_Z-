#include<bits/stdc++.h>
using namespace std; 

class Solution {
    bool expr(int &i, string &s){
        //Base case 
        if(s[i] == 't') {
            i++; 
            return true; 
        }
        if(s[i] == 'f'){
            i++; 
            return false;
        }  

        if(s[i] == '!'){
            i+=2; 
            bool op = !expr(i, s); 
            i++; 
            return op; 
        }
        if(s[i] == '&' || s[i] == '|'){
            char op = s[i]; 
            i += 2; 
            bool res = (op == '&');
            while(s[i] != ')'){
                if(s[i]==','){
                    i++; 
                    continue; 
                }
                bool operand = expr(i, s); 
                if(op == '&'){
                    res = res && operand; 
                }else{
                    res = res || operand; 
                }
            }
            i++; 
            return res; 
        }
        return false; 
    }
public:
    bool parseBoolExpr(string expression) {
        int i = 0; 
        return expr(i, expression); 
    }
};

int main(){
    Solution sol; 
    string expression = "|(&(t,f,t),!(t))"; 
    cout << sol.parseBoolExpr(expression) << endl; 
    return 0; 
}