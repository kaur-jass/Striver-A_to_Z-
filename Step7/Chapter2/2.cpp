#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    void generate(int n, const string curr, vector<string> &result){
        if(curr.length() == 2*n){
            result.push_back(curr); 
            return; 
        }
        int cnt1 = 0; 
        int cnt2 = 0; 
        for(int i = 0; i<curr.length(); i++){
            if(curr[i] == '(') cnt1++;
            else cnt2++;  
        }
        if(cnt1 < n){
            generate(n, curr+'(', result); 
        }
        if(cnt2 < cnt1){
            generate(n, curr+')', result);
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = ""; 
        vector<string> result; 
        generate(n, curr, result); 
        return result; 
    }
};
int main(){
    Solution sol; 
    int n = 3; 
    vector<string> result = sol.generateParenthesis(n); 
    for(auto str : result){
        cout<<str<<endl; 
    }
    return 0; 
}