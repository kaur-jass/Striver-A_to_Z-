#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<string>> dp;

    string solve(int i, int j, string &s, string &t) {

        // Base cases
        if(i == s.length())
            return t.substr(j);

        if(j == t.length())
            return s.substr(i);

        if(dp[i][j] != "#")
            return dp[i][j];

        // Same character → take once
        if(s[i] == t[j]) {
            return dp[i][j] = s[i] + solve(i+1, j+1, s, t);
        }

        // Different → try both
        string a = s[i] + solve(i+1, j, s, t);
        string b = t[j] + solve(i, j+1, s, t);

        return dp[i][j] = (a.length() <= b.length() ? a : b);
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        dp.assign(n, vector<string>(m, "#"));

        return solve(0, 0, str1, str2);
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    Solution obj;
    cout << obj.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}