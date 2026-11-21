// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

// using memoization to find the longest common subsequence string
class Solution {
    vector<vector<string>> dp;
    string solve(int i, int j, string &s, string &t){
        if(i < 0 || j < 0) return "";
        if(dp[i][j] != "#") return dp[i][j];
        if(s[i] == t[j]) {
            return dp[i][j] = solve(i-1, j-1, s, t) + s[i]; 
            // so that i will return correct string not the reversed one as we are adding the character at the end of the string
        }
        string a = solve(i-1, j, s, t);
        string b = solve(i, j-1, s, t);
        return dp[i][j] = (a.size() >= b.size() ? a : b);
    }
public:
    string lcs(string s, string t){
        int n = s.length(); 
        int m = t.length();
        dp.assign(n, vector<string>(m, "#"));
        return solve(n-1, m-1, s, t);
    }
};

int main(){
    string s, t; 
    cin >> s >> t; 
    Solution obj; 
    cout << obj.lcs(s, t) << endl; 
    return 0; 
}