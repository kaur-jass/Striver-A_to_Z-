#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> prev; 
    int solve(int m, int n, vector<vector<int>>& grid){
        for(int i=0; i<grid.size(); i++){
            vector<int> curr(n, 0);
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0) curr[j] = grid[i][j]; 
                else{
                    int up = grid[i][j]; 
                    if(i>0) up += prev[j]; 
                    else up += 1e9; 
                    int left = grid[i][j]; 
                    if(j>0) left += curr[j-1]; 
                    else left += 1e9; 
                    curr[j] = min(up, left); 
                }
            }
            prev = curr; 
        }
        return prev[m-1]; 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        prev.resize(n, -1); 
        return solve(m, n, grid); 
    }
}; 

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << sol.minPathSum(grid) << endl;
    return 0;
}