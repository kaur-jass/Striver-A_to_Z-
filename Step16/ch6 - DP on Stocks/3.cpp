#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<vector<int>>> dp; 
    int profit(vector<int>& prices, int idx, int buy, int trade){
        if(idx == prices.size() || trade == 0) return 0; 
        if(dp[idx][buy][trade] != -1) return dp[idx][buy][trade]; 
        int pro = 0; 
        if(buy == 0){
            pro = max(-prices[idx] + profit(prices, idx+1, 1, trade), profit(prices, idx+1, 0, trade)); 
        }
        else{
            pro = max(prices[idx] + profit(prices, idx+1, 0, trade-1), profit(prices, idx+1, 1, trade)); 
        }
        return dp[idx][buy][trade] = pro; 
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1))); 
        return profit(prices, 0, 0, 2); 
    }
};
int main(){
    Solution s; 
    cout << "Maximum profit: "; 
    vector<int> prices = {3,3,5,0,0,3,1,4}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}