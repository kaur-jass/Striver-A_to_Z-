#include<bits/stdc++.h>
using namespace std; 
class Solution{
    vector<vector<int>> dp;
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            dp.resize(n+1, vector<int>(2, 0));
            dp[n][0] = dp[n][1] = 0;
            long profit = 0;
            for(int ind = n-1; ind>=0; ind--){
                for(int buy = 0; buy<=1; buy++){   
                    if(buy == 0){ // We can buy the stock
                        profit = max(0 + dp[ind+1][0], -prices[ind] + dp[ind+1][1]);
                    }
                    if(buy == 1){ // We can sell the stock
                        profit = max(0 + dp[ind+1][1], prices[ind] + dp[ind+1][0]);
                    }
                    dp[ind][buy] = profit;
                }
            }
            return dp[0][0];
    }
};

int main(){
    Solution s; 
    vector<int> prices = {7,1,5,3,6,4}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}