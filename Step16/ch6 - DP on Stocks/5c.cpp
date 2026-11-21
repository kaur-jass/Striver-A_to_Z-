#include<bits/stdc++.h>
using namespace std;
// cool down =  1 day after selling, you cannot buy on the next day
class Solution {
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        dp.resize(n, vector<int>(2, -1)); 
        // tabulation approach
        for(int idx = n-1; idx >= 0; idx--){
            dp[idx][0] = max(-prices[idx] + (idx+1 < n ? dp[idx+1][1] : 0), (idx+1 < n ? dp[idx+1][0] : 0)); 
            dp[idx][1] = max(prices[idx] + (idx+2 < n ? dp[idx+2][0] : 0), (idx+1 < n ? dp[idx+1][1] : 0)); 
        }
        return dp[0][0];
    }
};

int main(){
    Solution s; 
    cout << "Maximum profit: "; 
    vector<int> prices = {1,2,3,0,2}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}