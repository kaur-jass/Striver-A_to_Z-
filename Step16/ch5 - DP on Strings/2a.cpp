#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> dp;
public:
    string lcs(string s, string t){
        int n = s.length(); 
        int m = t.length();
        // using standard table filling approach to find the longest common subsequence string
        dp.assign(n+1, vector<string>(m+1, ""));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0) dp[i][j] = "";
                else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + s[i-1];
                else dp[i][j] = (dp[i-1][j].size() >= dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1]);
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