#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp; 
    int solve(int m, int n, vector<vector<int>>& grid){
        if(m == 0 && n == 0) return grid[m][n]; 
        if (m<0 || n<0) return 1e9; 
        if(dp[m][n] != -1) return dp[m][n]; 
        dp[m][n] = grid[m][n] + min(solve(m-1, n, grid), solve(m, n-1, grid)); 
        return dp[m][n]; 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        dp.resize(m, vector<int>(n, -1)); 
        return solve(m-1, n-1, grid); 
    }
}; 

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << sol.minPathSum(grid) << endl;
    return 0;
}