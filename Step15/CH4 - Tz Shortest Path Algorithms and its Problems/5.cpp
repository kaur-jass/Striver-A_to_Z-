#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1; 
        vector<vector<int>> dist(n, vector<int>(m, 1e9)); 
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int,int>>>
        >pq; 
        pq.push({1,{0,0}}); 
        dist[0][0] = 1; 
        int delRow[] = {-1,-1,-1,0,0,1,1,1};
        int delCol[] = {-1,0,1,-1,1,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top(); 
            int dis = it.first;
            int r = it.second.first; 
            int c = it.second.second; 
            pq.pop();
            for(int k = 0; k<8; k++){
                int nr = r+delRow[k]; 
                int nc = c+delCol[k]; 
                if(nr>=0 && nc>=0 && nr<n && nc<m && dist[nr][nc] > dis+1 && grid[nr][nc] == 0){
                    dist[nr][nc] = dis+1; 
                    pq.push({dis+1, {nr, nc}});
                }
            }

        }
        if(dist[n-1][m-1] == 1e9) return -1; 
        return dist[n-1][m-1]; 
    }
};
int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0,1},
        {1,0}
    };

    int ans = obj.shortestPathBinaryMatrix(grid);

    cout << ans << endl;

    return 0;
}