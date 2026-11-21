#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp; 
    int solve(int i, int j, string &s){
        if(i>j) return 0; // they got in the middle and cross each other 
        if(i == j) return 1; // ex - "a"
        if(dp[i][j] != -1) return dp[i][j]; 
        if(s[i] == s[j]){ // Match found
            return dp[i][j] = 2+ solve(i+1, j-1, s); 
        }
        return dp[i][j] = max(solve(i+1, j, s), solve(i, j-1, s)); 
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(); 
        dp.assign(n, vector<int>(n, -1)); 
        return  solve(0, n-1, s); 
    }
};


int main(){
    string s; 
    cin >> s; 
    Solution obj; 
    cout << obj.longestPalindromeSubseq(s) << endl; 
    return 0; 
}