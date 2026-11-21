#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int longestCommonSubstring(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(n+1, vector<int>(m+1, 0));
        int ans = 0;
        // already all are zero no need to initialize the first row and first column with 0s as we have already initialized the dp array with 0s
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0; // if the characters are not equal, we cannot extend the substring, so we set it to 0
                }
            }
        }
        return ans;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.longestCommonSubstring(s, t) << endl;
    return 0;
}