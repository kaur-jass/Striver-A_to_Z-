#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[n - 1];
    }
};
int main(){
    Solution s; 
    vector<int> prices = {7,1,5,3,6,4}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}