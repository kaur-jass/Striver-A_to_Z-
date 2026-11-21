#include<bits/stdc++.h>
using namespace std;
// cool down =  1 day after selling, you cannot buy on the next day
class Solution {
    vector<vector<int>> dp;
    int profit(vector<int>& prices, int idx, int buy){
        if(idx >= prices.size()) return 0; 
        if(dp[idx][buy] != -1) return dp[idx][buy]; 
        int pro = 0; 
        if(buy == 0){
            pro = max(-prices[idx] + profit(prices, idx+1, 1), profit(prices, idx+1, 0)); 
        }
        else{
            pro = max(prices[idx] + profit(prices, idx+2, 0), profit(prices, idx+1, 1)); 
        }
        return dp[idx][buy]= pro; 
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        dp.resize(n, vector<int>(2, -1)); 
        return profit(prices, 0, 0); 
    }
};

int main(){
    Solution s; 
    cout << "Maximum profit: "; 
    vector<int> prices = {1,2,3,0,2}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}