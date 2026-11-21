#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();  
        int fresh = 0, time = 0;  
        queue<pair<int, int>> q; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2) q.push({i,j}); 
                else if(grid[i][j] == 1) fresh++; 
            }      
        }
        // BFS TRAVERSAL:
        while(!q.empty()){
            int size = q.size(); 
            bool spread = false; 
            for(int i = 0; i<size; i++){
                int r = q.front().first;
                int c = q.front().second; 
                q.pop();
                if(r-1 >= 0 && grid[r-1][c] == 1){
                    fresh--;
                    grid[r-1][c] = 2; 
                    q.push({r-1,c}); 
                    spread = true; 
                }
                if(r+1 < m && grid[r+1][c] == 1){
                    fresh--;
                    grid[r+1][c] = 2; 
                    q.push({r+1,c}); 
                    spread = true;
                }
                if(c-1 >= 0 && grid[r][c-1] == 1){
                    fresh--;
                    grid[r][c-1] = 2; 
                    q.push({r,c-1}); 
                    spread = true;
                }
                if(c+1 < n && grid[r][c+1] == 1){
                    fresh--;
                    grid[r][c+1] = 2; 
                    q.push({r,c+1});
                    spread = true; 
                }
            }
            if(spread) time++; 
        }
        return fresh == 0 ? time : -1; 
    }
};

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution sol;
    cout << sol.orangesRotting(grid) << endl; 
    return 0;
}