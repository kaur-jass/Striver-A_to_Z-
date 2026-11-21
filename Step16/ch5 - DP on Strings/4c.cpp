// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;
// Space optimization of the previous solution
class Solution {
    vector<int> prev, curr;
public:
    int longestPalindromeSubseq(string s){
        int n = s.length(); 
        string t = s;
        reverse(t.begin(), t.end());
        int m = t.length();
        prev.assign(m+1, 0);
        curr.assign(m+1, 0);
        // prev[0] = 0; // unncessary as we have already initialized the dp array with 0s
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
        return curr[m];
    }
};

int main(){
    string s; 
    cin >> s; 
    Solution obj; 
    cout << obj.longestPalindromeSubseq(s) << endl; 
    return 0; 
}