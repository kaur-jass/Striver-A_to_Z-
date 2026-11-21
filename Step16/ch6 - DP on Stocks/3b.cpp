#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int cap = 1; cap <= 2; cap++) {

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

        return after[1][2];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int max_profit = solution.maxProfit(prices);
    cout << "Maximum Profit: " << max_profit << endl;
    return 0;
}