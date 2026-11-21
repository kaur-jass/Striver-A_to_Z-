#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        dp.assign(n, vector<int>(amount+1, -1));
        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0) dp[0][a] = a / coins[0]; 
            else dp[0][a] = 1e9; 
        }
        for(int idx=1; idx<n; idx++){
            for(int a=0; a<=amount; a++){
                int notTake = 0 + dp[idx-1][a];
                int take = 1e9;
                if(coins[idx] <= a) take = 1 + dp[idx][a-coins[idx]];
                dp[idx][a] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
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