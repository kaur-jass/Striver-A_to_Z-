#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[ind][buy][cap]
        // buy = 0 -> can sell
        // buy = 1 -> can buy
        // cap = number of transactions remaining
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );

        // Base case:
        // dp[n][buy][cap] = 0
        // for(int buy = 0; buy <= 1; buy++) {
            // for(int cap = 0; cap <= 2; cap++) {
            //     dp[n][buy][cap] = 0;
            // }
        // }
        // Already initialized to 0

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int cap = 1; cap <= 2; cap++) { // cap = 0 means no transactions left, so we start from cap = 1, it is a base case 

                    if (buy == 1) {

                        // Buy or skip
                        dp[ind][buy][cap] = max(
                            -prices[ind] + dp[ind + 1][0][cap],
                            dp[ind + 1][1][cap]
                        );

                    }
                    else {

                        // Sell or skip
                        dp[ind][buy][cap] = max(
                            prices[ind] + dp[ind + 1][1][cap - 1],
                            dp[ind + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int max_profit = solution.maxProfit(prices);
    cout << "Maximum Profit: " << max_profit << endl;
    return 0;
}