#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, 1e9)); 
        for(int i = 0; i<n; i++){
            dp[i][i] = 0;
        }
        for(auto &it : edges){
            int u = it[0]; 
            int v = it[1]; 
            int wt = it[2]; 
            dp[u][v] = wt; 
            dp[v][u] = wt; 
        }
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dp[i][k] == 1e9 || dp[k][j] == 1e9) continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        vector<int> city(n); 
        for(int i = 0; i<n; i++){
            int cnt = 0; 
            for(int j = 0; j<n; j++){
                if(i != j  && dp[i][j]<=distanceThreshold) cnt++; 
            }
            city[i] = cnt; 
        }
        int mini = INT_MAX; 
        for(int i =0; i<n; i++){
            mini = min(city[i], mini); 
        }
        for(int i = n-1; i>=0; i--){
            if(city[i] == mini) return i; 
        }
        return -1; 
    }
};
int main() {
    Solution obj;

    int n = 4;
    vector<vector<int>> edges = {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };

    int distanceThreshold = 4;

    cout << obj.findTheCity(n, edges, distanceThreshold) << endl;

    return 0;
}