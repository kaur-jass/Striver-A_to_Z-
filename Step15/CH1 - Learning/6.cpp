#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: 
        void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
            vis[node] = 1; 
            ls.push_back(node); 
            // traverse a;; its neighbours
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    dfs(it, adj, vis, ls); 
                }
            }
        }
    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            // code here :
            int vis[V] = {0};
            int start = 0; 
            vector<int> ls; 
            dfs(start, adj, vis, ls); 
            return ls;
        }
};

int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Run DFS from node 0
    Solution sol;
    vector<int> result = sol.dfsOfGraph(V, adj);
    // Print traversal
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}