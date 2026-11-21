#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp; 
    int solve(int m, int n, vector<vector<int>>& grid){
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j]; 
                else{
                    int up = grid[i][j]; 
                    if(i>0) up += dp[i-1][j]; 
                    else up += 1e9; 
                    int left = grid[i][j]; 
                    if(j>0) left += dp[i][j-1]; 
                    else left += 1e9; 
                    dp[i][j] = min(up, left); 
                }
            }
        }
        return dp[m-1][n-1]; 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        dp.resize(m, vector<int>(n, -1)); 
        return solve(m, n, grid); 
    }
}; 

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << sol.minPathSum(grid) << endl;
    return 0;
}