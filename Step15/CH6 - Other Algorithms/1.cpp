// Tarjan's Algorithm to find Bridges (Critical Connections)

#include<bits/stdc++.h>
using namespace std; 


class Solution{
    private: 
        int timer = 1;
        void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &ans){
            vis[node] = 1;
            tin[node] = low[node] = timer++;
            
            for(auto it: adj[node]){
                if(it == parent) continue;
                if(!vis[it]){
                    dfs(it, node, vis, tin, low, adj, ans);
                    low[node] = min(low[node], low[it]);
                    if(low[it] > tin[node]){
                        ans.push_back({node, it});
                    }
                }
                else{
                    low[node] = min(low[node], tin[it]);
                }
            }
        }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            // build graph
            vector<vector<int>> adj(n);
            for(auto it: connections){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            vector<int> vis(n, 0), tin(n, -1), low(n, -1);
            vector<vector<int>> ans;
            dfs(0, -1, vis, tin, low, adj, ans);
            return ans;
        }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    for(int i = 0; i < m; i++){
        cin >> connections[i][0] >> connections[i][1];
    }
    Solution obj;
    vector<vector<int>> ans = obj.criticalConnections(n, connections);
    for(auto it: ans){
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}