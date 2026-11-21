#include<bits/stdc++.h>
using namespace std; 

class DisjointSet{
    vector<int> parent, rank, size; 
    public:
        DisjointSet(int n){
            parent.resize(n+1); 
            rank.resize(n+1, 0); 
            size.resize(n+1, 1); 
            for(int i = 0; i<=n; i++) parent[i] = i; 
        }
        int findUPar(int node){
            if(node == parent[node]) return node; 
            return parent[node] = findUPar(parent[node]); 
        }
        void UnionByRank(int u, int v){
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v; 
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u; 
                rank[ulp_u]++; 
            }
        }

        void UnionBySize(int u, int v){
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u]; 
            }
            else{
                parent[ulp_v] = ulp_u; 
                size[ulp_u] += size[ulp_v]; 
            }
        }
}; 

class Solution {
    private:
        bool isValid(int adjr, int adjc, int n, int m){
            return (adjr >= 0 && adjr<n && adjc >= 0 && adjc < m); 
        }
    public:
        vector<int> numOfIslands(int n, int m, vector<vector<int>> & operators){
            DisjointSet ds(n*m); 
            int vis[n][m]; 
            memset(vis, 0, sizeof(vis)); 
            int cnt = 0; 
            vector<int> ans;
            for(auto it : operators){
                int row = it[0]; 
                int col = it[1]; 
                if(vis[row][col] == 1){
                    ans.push_back(cnt); 
                    continue; 
                }
                vis[row][col] = 1; 
                cnt++; 
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, +1, 0, -1};
                for(int i = 0; i<4; i++){
                    int adjr = row + dr[i]; 
                    int adjc = col + dc[i]; 
                if(isValid(adjr, adjc, n, m) && vis[adjr][adjc] == 1){
                    // Union the current cell with the adjacent cell
                    int nodeNo = row*m + col;
                    int adjNodeNo = adjr*m + adjc;
                    if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                        cnt--; 
                        ds.UnionBySize(nodeNo, adjNodeNo); 
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
}; 

int main(){
    int n = 5, m = 5; 
    vector<vector<int>> operators = {{0,0}, {0,1}, {1,2}, {2,1}, {1,1}}; 
    Solution obj; 
    vector<int> ans = obj.numOfIslands(n, m, operators); 
    for(auto it : ans) cout<<it<<" "; 
    cout<<endl; 
    return 0; 
}
