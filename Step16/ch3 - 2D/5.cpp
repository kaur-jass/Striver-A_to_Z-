#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m,vector<vector<int>>& triangle, vector<vector<int>>& dp){ 
        for(int i = 0; i<m; i++){
            int n = triangle[i].size(); 
            dp[i].resize(n, -1);
            for(int j = 0; j<n;j++){
                if(i == 0 && j== 0) dp[i][j] = triangle[i][j];
                else{
                    int up = triangle[i][j]; 
                    if(i>0 && j < dp[i-1].size()) up += dp[i-1][j]; 
                    else up += 1e9; 

                    int left = triangle[i][j]; 
                    if(i>0 && j>0) left += dp[i-1][j-1]; 
                    else left += 1e9; 

                    dp[i][j] = min(up, left); 
                }
            }
        }
        int ans = INT_MAX; 
        for(int x : dp[m-1]){
            ans = min(ans, x); 
        } 
        return ans; 
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(); 
        vector<vector<int>> dp(m);  
        return solve(m, triangle, dp); 
    }
};

int main(){
    Solution sol;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << sol.minimumTotal(triangle) << endl;
    return 0;
}