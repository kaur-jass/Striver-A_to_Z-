#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prev, curr;
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        prev.assign(amount+1, 0);
        curr.assign(amount+1, 0);
        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0) prev[a] = a / coins[0]; 
            else prev[a] = 1e9; 
        }
        for(int idx=1; idx<n; idx++){
            for(int a=0; a<=amount; a++){
                int notTake = 0 + prev[a];
                int take = 1e9;
                if(coins[idx] <= a) take = 1 + curr[a-coins[idx]];
                curr[a] = min(take, notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
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