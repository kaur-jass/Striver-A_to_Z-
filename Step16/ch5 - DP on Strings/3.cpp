#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(int i, int j, string &s, string &t) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s, t);
        }
        return dp[i][j] = 0; // if the characters are not equal, we cannot extend the substring, so we return 0
    }

public:
    int longestCommonSubstring(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, s, t));
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