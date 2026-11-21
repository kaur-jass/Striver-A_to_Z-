// Longest common subsequence
// Using Shifting of indices to avoid negative indexing and using memoization for optimization.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, string &s, string &t){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1]) return dp[i][j] = 1 + solve(i-1, j-1, s, t);
        return dp[i][j] = max(solve(i-1, j, s, t), solve(i, j-1, s, t));
    }
public:
    int lcs(string s, string t){
        int n = s.length(); 
        int m = t.length();
        dp.assign(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, t);
    }
};

int main(){
    string s, t; 
    cin >> s >> t; 
    Solution obj; 
    cout << obj.lcs(s, t) << endl; 
    return 0; 
}