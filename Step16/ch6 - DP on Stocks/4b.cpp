#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();


        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int cap = 1; cap <= k; cap++) {

                    if (buy == 1) {
                        // Buy or skip
                        cur[buy][cap] = max(
                            -prices[ind] + after[0][cap],
                            after[1][cap]
                        );
                    }
                    else {
                        // Sell or skip
                        cur[buy][cap] = max(
                            prices[ind] + after[1][cap - 1],
                            after[0][cap]
                        );
                    }
                }
            }

            after = cur;
        }

        return after[1][k];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2; // Maximum number of transactions allowed
    int max_profit = solution.maxProfit(prices, k);
    cout << "Maximum Profit: " << max_profit << endl;
    return 0;
}