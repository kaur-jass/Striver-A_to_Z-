#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp; 
    int solve(int m, int n){
        // Base Case 
        if(m == 0 && n == 0) return 1; 
        if(m<0 || n<0) return 0;
        if(dp[m][n] != -1) return dp[m][n]; 
        dp[m][n] = solve(m-1, n) + solve(m, n-1); 
        return dp[m][n]; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size(); 
        if(obstacleGrid[0][0] == 1|| obstacleGrid[m-1][n-1] == 1) return 0;
        dp.resize(m, vector<int>(n, -1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0; 
            }
        }
        return solve (m-1, n-1);
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    Solution obj;
    cout << obj.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}