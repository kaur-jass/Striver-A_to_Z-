#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalin(const string&s,int l,int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int f(int i , const string&s,vector<int> &dp){
        if(i == s.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = 1e9;
        for(int j = i ; j < s.size(); j++){       
            if(ispalin(s, i, j)){
                int cnt = 1 + f(j+1,s,dp);
                mini = min(mini,cnt);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp)-1;
    }
};


int main(){
    string s = "aab"; 
    Solution obj; 
    cout << "The minimum cuts required to partition the string into palindromic substrings are : " << obj.minCut(s); 
    return 0; 
}