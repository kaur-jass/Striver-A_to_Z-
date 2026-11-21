#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp; 
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        dp.resize(n, vector<int>(amount+1, -1));
        for(int T=0; T<=amount; T++) dp[0][T] = (T % coins[0] == 0) ? 1 : 0;
        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=amount; T++){
                int dont_pick = dp[idx-1][T]; 
                int pick = 0; 
                if(coins[idx]<=T) pick = dp[idx][T-coins[idx]];
                dp[idx][T] = pick + dont_pick; 
            }
        }
        return dp[n-1][amount]; 
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