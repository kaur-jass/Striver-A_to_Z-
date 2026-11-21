#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp; 
public:
    int minDistance(string word1, string word2) {
      int n = word1.length(); 
      int m = word2.length(); 
      dp.assign(n, vector<int>(m, -1));

      // using tabulation to find the longest common subsequence
      for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
              if(word1[i] == word2[j]){
                  dp[i][j] = 1 + (i>0 && j>0 ? dp[i-1][j-1] : 0); 
              } else {
                  dp[i][j] = max(i>0 ? dp[i-1][j] : 0, j>0 ? dp[i][j-1] : 0); 
              }
          }
      }
      return n + m - 2*dp[n-1][m-1]; // total deletions i need from both word1 and word2 
    }
};

int main(){
    string word1, word2; 
    cin >> word1 >> word2; 
    Solution obj; 
    cout << obj.minDistance(word1, word2) << endl; 
    return 0; 
}