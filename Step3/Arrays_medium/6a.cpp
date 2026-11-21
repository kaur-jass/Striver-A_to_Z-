#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i = 0; i<n; i++)
        {
            int cost = prices[i]-mini;
            profit = max(profit, cost);
            mini = min(prices[i], mini);
        }
        return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}