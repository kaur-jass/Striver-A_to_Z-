#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // we have to find the path which has lowest maximum cell value.
        // basic ques.... huhhhhhhhh
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m,0));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int,int>>>
        >pq; 
        pq.push({grid[0][0], {0,0}});  // push elevation 
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top(); 
            int ele = it.first; 
            int r = it.second.first; 
            int c = it.second.second;
            pq.pop();
            if(vis[r][c] == 1) continue; 
            vis[r][c] = 1;
            if(r == n-1 && c == m-1) return ele;
            for(int k = 0; k<4; k++){
                int nr = r+dr[k]; 
                int nc = c+dc[k];   
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(!vis[nr][nc]){
                        pq.push({max(ele, grid[nr][nc]), {nr, nc}});  // push the cost comes so far 
                    }
                }
            }
        }   
        return -1; 
    }
};

int main(){
    int n, m; 
    cin>>n>>m; 
    vector<vector<int>> grid(n, vector<int>(m)); 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j]; 
        }
    }
    Solution obj; 
    cout<<obj.swimInWater(grid)<<endl;
    return 0; 
}