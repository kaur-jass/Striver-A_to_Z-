#include<bits/stdc++.h>
using namespace std; 

class Solution {
    vector<vector<vector<int>>> dp;
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m) {
        // Base case: if out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9; // Return a very small number

        // Check if already computed
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // Base case: if at the last row
        if (i == n - 1) {
            if (j1 == j2)
                return grid[i][j1]; // Both robots on the same cell
            else
                return grid[i][j1] + grid[i][j2]; // Different cells
        }

        int maxi = -1e9;
        // Explore all possible moves for both robots
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if (j1 == j2)
                    value = grid[i][j1]; // Same cell
                else
                    value = grid[i][j1] + grid[i][j2]; // Different cells

                value += solve(i + 1, j1 + dj1, j2 + dj2, grid, n, m);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi; // Store and return the result
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1))); 
        return solve(0, 0, m - 1, grid, n, m);
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    Solution obj;
    cout << obj.cherryPickup(grid) << endl;
    return 0;
}