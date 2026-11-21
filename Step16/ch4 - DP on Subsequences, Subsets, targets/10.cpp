#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp;
    int solve(int idx, int maxWeight, vector<int>& weight, vector<int>& value){
        if(idx == 0){
            if(weight[0] <= maxWeight)
                return (int)(maxWeight / weight[0]) * value[0];
            return 0; 
        }
        if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight]; 
        int dont_pick = solve(idx-1, maxWeight, weight, value); 
        int pick = INT_MIN; 
        if(weight[idx]<=maxWeight) pick = value[idx] + solve(idx, maxWeight-weight[idx], weight, value);
        return dp[idx][maxWeight] = max(pick, dont_pick); 
    }
public:
    int unbounded_knapsack(int maxWeight, vector<int>& weight, vector<int>& value) {
        int n = weight.size();
        dp.resize(n, vector<int>(maxWeight + 1, -1));
        return solve(n - 1, maxWeight, weight, value);        
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