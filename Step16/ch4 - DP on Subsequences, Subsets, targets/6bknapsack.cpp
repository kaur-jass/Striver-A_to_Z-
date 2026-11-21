#include<bits/stdc++.h>
using namespace std; 

class Solution {
    vector<vector<int>> dp;
public:
    int knapsack(int n, int W, vector<int> &wt, vector<int> &val){
        dp.assign(n, vector<int>(W+1, 0));
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= w) dp[0][w] = val[0]; 
            else dp[0][w] = 0; 
        }
        for(int idx=1; idx<n; idx++){
            for(int w=0; w<=W; w++){
                int notTake = 0 + dp[idx-1][w]; 
                int take = INT_MIN; 
                if(wt[idx] <= w) take = val[idx] + dp[idx-1][w-wt[idx]];
                dp[idx][w] = max(take, notTake);
            }
        }
        return dp[n-1][W];
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