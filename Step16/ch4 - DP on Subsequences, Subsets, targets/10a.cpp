#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp; 
public:
    int unbounded_knapsack(int maxWeight, vector<int>& weight, vector<int>& value) {
        int n = weight.size();
        dp.resize(n, vector<int>(maxWeight + 1, -1));
        for(int W=0; W<=maxWeight; W++){
            if(weight[0] <= W )
                dp[0][W] = (int)(W / weight[0]) * value[0];
            else
                dp[0][W] = 0; 
        }
        for(int idx=1; idx<n; idx++){
            for(int W=0; W<=maxWeight; W++){
                int dont_pick = dp[idx-1][W]; 
                int pick = INT_MIN; 
                if(weight[idx]<=W) pick = value[idx] + dp[idx][W-weight[idx]];
                dp[idx][W] = max(pick, dont_pick); 
            }
        }
        return dp[n-1][maxWeight];        
    }
}; 

int main(){
    int n, maxWeight; 
    cin >> n >> maxWeight; 
    vector<int> weight(n), value(n); 
    for(int i=0; i<n; i++) cin >> weight[i]; 
    for(int i=0; i<n; i++) cin >> value[i]; 
    Solution obj; 
    cout << obj.unbounded_knapsack(maxWeight, weight, value) << endl; 
    return 0; 
}