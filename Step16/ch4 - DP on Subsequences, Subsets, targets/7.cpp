#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int solve(int idx, int amount, vector<int>& coins){
        if(idx == 0){
            if(amount % coins[0] == 0) return amount / coins[0]; 
            else return 1e9; 
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = 0 + solve(idx-1, amount, coins);
        int take = 1e9;
        if(coins[idx] <= amount) take = 1 + solve(idx, amount-coins[idx], coins);
        return dp[idx][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        dp.assign(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins);
        if(ans >= 1e9) return -1;
        return ans; 
    }
};

int main(){
    int n, amount; 
    cin >> n >> amount; 
    vector<int> coins(n); 
    for(int i=0; i<n; i++) cin >> coins[i]; 
    Solution obj; 
    cout << obj.coinChange(coins, amount) << endl; 
    return 0; 
}