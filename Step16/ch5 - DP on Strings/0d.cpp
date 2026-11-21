// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prev, curr;
public:
    int lcs(string s, string t){
        int n = s.length(); 
        int m = t.length();
        prev.assign(m+1, 0);
        curr.assign(m+1, 0);
        // dp[0][0] = 0; // unncessary as we have already initialized the dp array with 0s
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main(){
    string s, t; 
    cin >> s >> t; 
    Solution obj; 
    cout << obj.lcs(s, t) << endl; 
    return 0; 
}