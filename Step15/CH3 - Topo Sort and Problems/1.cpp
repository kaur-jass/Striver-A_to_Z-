#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node, vector<int> adj[], int vis[], stack<int> &st){
        vis[node] = 1; 
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(node); 
    }
    vector<int> topoSort(int V, vector<int> adj[]) {
        int vis[V] = {0};
        stack<int> st;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
int main() {
    int V = 6;
    vector<int> adj[V];

    // Example directed graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution sol;
    vector<int> result = sol.topoSort(V, adj);
    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}