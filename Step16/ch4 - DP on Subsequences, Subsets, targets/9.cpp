#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp; 
    int solve(int idx, int amount, vector<int>& coins){
        if(amount == 0) return 1; 
        if(idx == 0){
            if(amount % coins[0] == 0) return 1; 
            return 0; 
        }
        if(dp[idx][amount] != -1) return dp[idx][amount]; 
        int dont_pick = solve(idx-1, amount, coins); 
        int pick = 0; 
        if(coins[idx]<=amount) pick = solve(idx, amount-coins[idx], coins);
        return dp[idx][amount] = pick + dont_pick; 
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        dp.resize(n, vector<int>(amount+1, -1)); 
        return solve(n-1, amount, coins); 
    }
};

int main(){
    int n, amount; 
    cin >> n >> amount; 
    vector<int> coins(n); 
    for(int i=0; i<n; i++) cin >> coins[i]; 
    Solution obj; 
    cout << obj.change(amount, coins) << endl; 
    return 0; 
}