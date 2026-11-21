#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(); 
        int m = heights[0].size(); 
        vector<vector<int>> dist(n, vector<int>(m, 1e9));  // this one is to store their minimum abs diff
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int,int>>>
        >pq; 
        pq.push({0, {0,0}});  // push efforts not height
        dist[0][0] = 0;  // i am storing now maximum effort so far 
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 
        while(!pq.empty()){
            auto it = pq.top(); 
            int effort = it.first; 
            int r = it.second.first; 
            int c = it.second.second;
            pq.pop(); 
            if(effort > dist[r][c]) continue;
            if(r == n-1 && c == m-1) return effort; 
            for(int k = 0; k<4; k++){
                int nr = r+dr[k]; 
                int nc = c+dc[k];   
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int egdediff = abs(heights[nr][nc] - heights[r][c]); 
                    int newEffort = max(effort, egdediff);
                    if(newEffort < dist[nr][nc]){
                        pq.push({newEffort, {nr, nc}}); 
                        dist[nr][nc] = newEffort; 
                    }
                }
            }
        }
        if(dist[n-1][m-1] == 1e9) return -1;
        return dist[n-1][m-1]; 
    }
};
int main() {
    Solution obj;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << obj.minimumEffortPath(heights) << endl;

    return 0;
}