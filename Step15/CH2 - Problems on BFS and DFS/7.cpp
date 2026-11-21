#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m,-1)); 
        queue<pair<int, int>> q; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j}); 
                    dist[i][j] = 0; 
                }
            }
        }
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 
        while(!q.empty()){
            pair<int, int> p = q.front(); 
            q.pop(); 
            int row = p.first; 
            int col = p.second; 
            for(int k = 0; k<4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];  
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(dist[nr][nc] == -1){
                        dist[nr][nc] = dist[row][col] + 1; 
                        q.push({nr, nc}); 
                    }
                }
            }
        }
        return dist; 
    }
};

int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(mat);
    for (const auto& row : result) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}