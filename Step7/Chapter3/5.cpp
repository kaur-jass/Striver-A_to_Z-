#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    bool solve(int i,string s, vector<string>& wordDict){
        int n = s.length(); 
        if(i == n) return true; 
        if (dp[i] != -1) return dp[i];
        for(int j = 0; j<wordDict.size(); j++){
            string word = wordDict[j]; 
            if(i + word.length() <= n && s.substr(i, word.length()) == word)
                if(solve(i+word.length(), s, wordDict)) return dp[i] = true;
        }
        return dp[i] = false; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.length(), -1);
        return solve(0,s, wordDict); 
    }
};

int main(){
    Solution sol; 
    string s = "leetcode"; 
    vector<string> wordDict = {"leet", "code"}; 
    cout<<sol.wordBreak(s, wordDict)<<endl; 
    return 0;
}