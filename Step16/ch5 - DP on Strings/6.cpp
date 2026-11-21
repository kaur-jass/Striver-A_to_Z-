#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp; 
    int lcs(int i, int j, string &word1, string &word2){
        if(i<0 || j<0) return 0; 
        if(dp[i][j] != -1) return dp[i][j]; 
        if(word1[i] == word2[j]){
            return dp[i][j] = 1 + lcs(i-1, j-1, word1, word2); 
        }
        return dp[i][j] = max(lcs(i-1, j, word1, word2), lcs(i, j-1, word1, word2)); 
    }
public:
    int minDistance(string word1, string word2) {
      int n = word1.length(); 
      int m = word2.length(); 
      dp.assign(n, vector<int>(m, -1));
      return n + m - 2*lcs(n-1, m-1, word1, word2); // total deletions i need from both word1 and word2 
    }
};

int main(){
    string word1, word2; 
    cin >> word1 >> word2; 
    Solution obj; 
    cout << obj.minDistance(word1, word2) << endl; 
    return 0; 
}