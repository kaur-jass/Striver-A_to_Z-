#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int r, int c, int n, int m ,vector<vector<char>>& grid, vector<vector<int>>& vis){
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 
        for(int k = 0; k<4; k++){
            int nr = r + dr[k]; 
            int nc = c + dc[k]; 
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && vis[nr][nc] == 0){
                vis[nr][nc] = 1; 
                dfs(nr, nc, n, m, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int cnt = 0 ; 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++; 
                    dfs(i, j, n, m, grid, vis); 
                }
            }
        }
        return cnt; 
    }
};

int main(){
    int n, m; 
    cin >> n >> m; 
    vector<vector<char>> grid(n, vector<char>(m)); 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) cin >> grid[i][j]; 
    }
    Solution ob; 
    cout << ob.numIslands(grid) << endl;
}