#include<bits/stdc++.h>
using namespace std; 

class Solution {
    vector<vector<int>> dp; 
    int solve(int idx, int W, vector<int> &wt, vector<int> &val){
        if(idx == 0){
            if(wt[0] <= W) return val[0]; 
            else return 0; 
        }
        if(dp[idx][W] != -1) return dp[idx][W]; 
        int notTake = 0 + solve(idx-1, W, wt, val); 
        int take = INT_MIN; 
        if(wt[idx] <= W) take = val[idx] + solve(idx-1, W-wt[idx], wt, val); 
        return dp[idx][W] = max(take, notTake); 
    }
public:
    int knapsack(int n, int maxWeight, vector<int> &wt, vector<int> &val){
        dp.assign(n, vector<int>(maxWeight+1, -1));  
        return solve(n-1, maxWeight, wt, val);
    }
}; 

int main(){
    int n, W; 
    cin >> n >> W; 
    vector<int> wt(n), val(n); 
    for(int i=0; i<n; i++) cin >> wt[i]; 
    for(int i=0; i<n; i++) cin >> val[i]; 
    Solution obj; 
    cout << obj.knapsack(n, W, wt, val) << endl; 
    return 0; 
}