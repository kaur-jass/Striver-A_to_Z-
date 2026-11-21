#include<bits/stdc++.h>
using namespace std; 
class Solution{
    public:
        void topoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]){
            vis[node] = 1; 
            for(auto &it : adj[node]){
                int v = it.first; 
                if(!vis[v]) topoSort(v, vis, st, adj);   
            }
            st.push(node); 
        }
        vector<int> ShortestPath(vector<vector<int>> &edges, int src, int n) {
            vector<pair<int, int>> adj[n]; 
            for(int i = 0; i<edges.size(); i++){
                int u = edges[i][0]; 
                int v = edges[i][1]; 
                int wt = edges[i][2]; 
                adj[u].push_back({v, wt}); 
            }
            // find the topo Sort
            vector<int> vis(n,0); 
            stack<int> st; 
            for(int i = 0; i<n; i++){
                if(!vis[i]){
                    topoSort(i, vis, st, adj); 
                }
            }
            vector<int> dist(n, 1e9); 
            dist[src]= 0; 
            while(!st.empty()){
                int node = st.top(); 
                st.pop(); 
                for(auto it : adj[node]){
                    int v = it.first; 
                    int wt = it.second; 
                    if(dist[node]+wt < dist[v]){
                        dist[v] = dist[node]+wt; 
                    }
                }
            }
            vector<int> ans(n, -1); 
            for(int i = 0; i<n; i++){
                if(dist[i] != 1e9){
                    ans[i] = dist[i]; 
                }
            }
            return ans; 
        }
};

#include<bits/stdc++.h>
using namespace std;

int main() {
    Solution obj;

    int n = 6;

    vector<vector<int>> edges = {
        // {u, v, wt}
        // u ----wt----> v
        {0,1,2},
        {0,4,1},
        {1,2,3},
        {4,2,2},
        {4,5,4},
        {2,3,6},
        {5,3,1}
    };

    int src = 0;

    vector<int> ans = obj.ShortestPath(edges, src, n);

    cout << "Shortest distances from source " << src << ":\n";

    for(int i = 0; i < ans.size(); i++) {
        cout << i << " -> " << ans[i] << endl;
    }

    return 0;
}