#include <bits/stdc++.h>

using namespace std;

class Solution {

    vector<vector<int>> dp;

public:

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        // dp[i][j] = LCS length of str1[0...i-1] and str2[0...j-1]
        dp.assign(n + 1, vector<int>(m + 1, 0));

        // Fill LCS table
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                if(str1[i-1] == str2[j-1]) {

                    dp[i][j] = 1 + dp[i-1][j-1];

                }
                else {

                    dp[i][j] = max(
                        dp[i-1][j],
                        dp[i][j-1]
                    );
                }
            }
        }

        // Backtracking to construct SCS
        int i = n;
        int j = m;

        string ans = "";

        while(i > 0 && j > 0) {

            // Common character → add only once
            if(str1[i-1] == str2[j-1]) {

                ans += str1[i-1];

                i--;
                j--;
            }

            // LCS came from top
            else if(dp[i-1][j] > dp[i][j-1]) {

                ans += str1[i-1];

                i--;
            }

            // LCS came from left
            else {

                ans += str2[j-1];

                j--;
            }
        }

        // Remaining characters
        while(i > 0) {

            ans += str1[i-1];

            i--;
        }

        while(j > 0) {

            ans += str2[j-1];

            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    string str1, str2;

    cin >> str1 >> str2;

    Solution obj;

    cout << obj.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}