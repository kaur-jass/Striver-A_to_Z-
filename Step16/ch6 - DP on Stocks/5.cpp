#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<vector<int>>> dp;
    int profit(vector<int>& prices, int idx, int buy, int cool){
        if(idx == prices.size()) return 0; 
        if(dp[idx][buy][cool] != -1) return dp[idx][buy][cool]; 
        int pro = 0; 
        if(cool == 1){ // Cooldown day → cannot buy/sell, simply skip
            return dp[idx][buy][cool] =  profit(prices, idx+1, buy, 0); 
        }
        if(buy == 0){
            pro = max(-prices[idx] + profit(prices, idx+1, 1, 0), profit(prices, idx+1, 0, 0)); 
        }
        else{
            pro = max(prices[idx] + profit(prices, idx+1, 0, 1), profit(prices, idx+1, 1, 0)); 
        }
        return dp[idx][buy][cool] = pro; 
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        dp.resize(n, vector<vector<int>>(2, vector<int>(2, -1))); 
        return profit(prices, 0, 0, 0); 
    }
};

int main(){
    Solution s; 
    cout << "Maximum profit: "; 
    vector<int> prices = {1,2,3,0,2}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}