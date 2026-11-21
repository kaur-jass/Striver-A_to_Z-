#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp; 
    int solve(int i, int j, string &s, string &rev){
        if(i < 0 || j < 0) return 0; // they got in the middle and cross each other 
        if(dp[i][j] != -1) return dp[i][j]; 
        if(s[i] == rev[j]){ // Match found
            return dp[i][j] = 1 + solve(i-1, j-1, s, rev); 
        }
        return dp[i][j] = max(solve(i-1, j, s, rev), solve(i, j-1, s, rev)); 
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(); 
        string rev = s;
        reverse(rev.begin(), rev.end());
        int m = rev.length();
        dp.assign(n, vector<int>(m, -1)); 
        return  n - solve(n-1, m-1, s, rev); 
    }
};


int main(){
    string s; 
    cin >> s; 
    Solution obj; 
    cout << obj.longestPalindromeSubseq(s) << endl; 
    return 0; 
}
