// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int lcs(string s, string t){
        int n = s.length(); 
        int m = t.length();
        dp.assign(n+1, vector<int>(m+1, 0));
        // dp[0][0] = 0; // unncessary as we have already initialized the dp array with 0s
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    string s, t; 
    cin >> s >> t; 
    Solution obj; 
    cout << obj.lcs(s, t) << endl; 
    return 0; 
}