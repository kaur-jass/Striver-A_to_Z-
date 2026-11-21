#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalin(const string&s,int l,int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            // i...j
            for (int j = i; j < n; j++) {
                if (ispalin(s, i, j)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};


int main(){
    string s = "aab"; 
    Solution obj; 
    cout << "The minimum cuts required to partition the string into palindromic substrings are : " << obj.minCut(s); 
    return 0; 
}