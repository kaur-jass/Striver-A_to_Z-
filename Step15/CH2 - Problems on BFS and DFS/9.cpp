#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int row, int col, int n, int m , vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1; 
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 
        for(int k = 0; k<4; k++){
            int nr = row + dr[k]; 
            int nc = col + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 1) dfs(nr, nc, n, m, grid, vis);  
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int cnt = 0;  
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0] == 1) dfs(i,0, n, m, grid, vis); 
            if(!vis[i][m-1] && grid[i][m-1] == 1) dfs(i,m-1, n, m, grid, vis); 
        }
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && grid[0][j] == 1) dfs(0, j, n, m, grid, vis); 
            if(!vis[n-1][j] && grid[n-1][j] == 1) dfs(n-1, j, n, m, grid, vis); 
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1) cnt++; 
            }
        }
        return cnt; 
    }
};

int main(){
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> grid(n, vector<int>(m)); 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) cin >> grid[i][j]; 
    }
    Solution ob; 
    cout << ob.numEnclaves(grid) << endl;
}