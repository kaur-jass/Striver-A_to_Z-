#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prev; 
    int solve(int m, int n, vector<vector<int>>& obstacleGrid){
        prev.resize(n, 0);
        for(int i = 0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j<n; j++){
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0; 
                    continue;
                }
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }
                int up  = 0;
                if(i>0) up = prev[j];
                int left = 0;
                if(j>0) left  = curr[j-1];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size(); 
        if(obstacleGrid[0][0] == 1|| obstacleGrid[m-1][n-1] == 1) return 0;
        return solve (m, n, obstacleGrid);
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