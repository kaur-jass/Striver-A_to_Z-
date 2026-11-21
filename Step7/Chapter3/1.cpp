#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool palindrome(string s){
        int left = 0; 
        int right = s.size()-1; 
        while(left < right){
            if(s[left] != s[right]) return false; 
                left++; 
                right--;
        }
        return true;
    }
    void generate(int idx,vector<string>& ans,vector<vector<string>>& result,int n,string s){
        // Base Case
        if(idx == n){
            result.push_back(ans); 
            return;
        }
        string st = ""; 
        for(int i = idx; i<n; i++){
            st.push_back(s[i]); 
            if(palindrome(st)){
                ans.push_back(st);
                generate(i+1, ans, result,n, s);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size(); 
        vector<string> ans; 
        vector<vector<string>> result; 
        generate(0,ans, result,n, s); 
        return result; 
    }
};
int main(){
    string s = "aabb"; 
    Solution sol; 
    vector<vector<string>> res = sol.partition(s); 
    for(auto vec : res){
        for(auto str : vec){
            cout<<str<<" "; 
        }
        cout<<endl; 
    }
    return 0; 
}