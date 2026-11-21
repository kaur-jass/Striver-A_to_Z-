// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    string lcs(string s, string t){
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
        // using strivers standard table filling approach to find the longest common subsequence string
        int i = n, j = m;
        string ans = "";
        int len = dp[n][m];
        int index = len - 1;
        for(int i = 0; i < len; i++) ans += '$'; // initializing the string with $ so that we can replace it with the characters of the longest common subsequence string
        while(i > 0 && j > 0){   // Using backtracking to find the longest common subsequence string from the dp table
            if(s[i-1] == t[j-1]){
                ans[index] = s[i-1];
                index--;
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main(){
    string s, t; 
    cin >> s >> t; 
    Solution obj; 
    cout << obj.lcs(s, t) << endl; 
    return 0; 
}