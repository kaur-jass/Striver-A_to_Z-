#include<bits/stdc++.h>
using namespace std;
class Solution { 
    vector<vector<int>> dp;  
    int profit(vector<int>& prices, int fee, int idx, int buy){ 
        if(idx == prices.size()) return 0;  
        if(dp[idx][buy] != -1) return dp[idx][buy];  
        int pro = 0;  
        if(buy == 0){ 
            pro = max(-prices[idx] + profit(prices, fee, idx+1, 1), 0 + profit(prices, fee, idx+1, 0)); 
        } 
        else{ 
            pro = max(prices[idx] - fee + profit(prices, fee, idx+1, 0), 0 + profit(prices, fee, idx+1, 1)); 
        } 
        return dp[idx][buy] = pro;  
    } 
 
public: 
    int maxProfit(vector<int>& prices, int fee) { 
        int n = prices.size();  
        dp.resize(n, vector<int>(2, -1));  
        return profit(prices, fee, 0, 0);  
    } 
}; 
int main(){ 
    Solution s;  
    cout << "Maximum profit: ";  
    vector<int> prices = {1,3,2,8,4,9};  
    int fee = 2;  
    cout << s.maxProfit(prices, fee) << endl;  
    return 0;  
}