#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;

    int f(int i, int j, bool istrue, string &exp,
          vector<vector<vector<int>>> &dp) {

        // Base case
        if (i > j) {
            return 0;
        }

        if (i == j) {
            if (istrue) {
                return exp[i] == 'T';
            } else {
                return exp[i] == 'F';
            }
        }

        if (dp[i][j][istrue] != -1) {
            return dp[i][j][istrue];
        }

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {

            int lt = f(i, k - 1, true, exp, dp);
            int lf = f(i, k - 1, false, exp, dp);
            int rt = f(k + 1, j, true, exp, dp);
            int rf = f(k + 1, j, false, exp, dp);

            if (exp[k] == '&') {
                if (istrue) {
                    ways = (ways + (1LL * lt * rt) % mod) % mod;
                } else {
                    ways = (ways + (1LL * lt * rf) % mod
                                  + (1LL * lf * rt) % mod
                                  + (1LL * lf * rf) % mod) % mod;
                }
            }
            else if (exp[k] == '|') {
                if (istrue) {
                    ways = (ways + (1LL * lt * rt) % mod
                                  + (1LL * lf * rt) % mod
                                  + (1LL * lt * rf) % mod) % mod;
                } else {
                    ways = (ways + (1LL * lf * rf) % mod) % mod;
                }
            }
            else { // XOR (^)
                if (istrue) {
                    ways = (ways + (1LL * lt * rf) % mod
                                  + (1LL * lf * rt) % mod) % mod;
                } else {
                    ways = (ways + (1LL * lt * rt) % mod
                                  + (1LL * lf * rf) % mod) % mod;
                }
            }
        }

        return dp[i][j][istrue] = ways % mod;
    }

public:
    int countWays(string &s) {
        int n = s.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return f(0, n - 1, true, s, dp);
    }
};

int main() {
    Solution sol;
    string expression = "T|F&T^F";
    cout << sol.countWays(expression) << endl;
    return 0;
}   