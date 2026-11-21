#include<bits/stdc++.h>
using namespace std; 

class Solution {
    vector<int> memo; 
    vector<vector<int>> dp; 
    int lcs(int i, int j, string &word1, string &word2){
        if(i<0 || j<0) return 0; 
        if(dp[i][j] != -1) return dp[i][j]; 
        if(word1[i] == word2[j]){
            return dp[i][j] = 1 + lcs(i-1, j-1, word1, word2); 
        }
        return dp[i][j] = max(lcs(i-1, j, word1, word2), lcs(i, j-1, word1, word2)); 
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(); 
        int m = word2.length(); 
        dp.assign(n, vector<int>(m, -1));
        if (lcs(n-1, m-1, word1, word2) == 0) return 0;
        return n + m - 2*lcs(n-1, m-1, word1, word2); // total deletions i need from both word1 and word2 
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();  
        if(n == 0 || n == 1) return n; 
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        memo.resize(n, 1);
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev < i; prev++){
               if(words[i].size() == words[prev].size() + 1 && minDistance(words[i], words[prev]) == 1){
                    memo[i] = max(memo[i] , 1+memo[prev]); 
                }
            }
        }
        return *max_element(memo.begin(), memo.end());
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = sol.longestStrChain(words);
    cout << "Length of Longest String Chain: " << result << endl;
    return 0;
}