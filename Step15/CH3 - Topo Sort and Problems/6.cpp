#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>>& graph){
        vis[node] = 1; 
        pathVis[node] = 1; 
        for(auto it : graph[node]){
            if (!vis[it]){
                if(dfs(it, vis, pathVis, graph)) return true; 
            }
            else if(pathVis[it] == 1){ // cycle found
                return true; 
            }
        }
        pathVis[node] = 0; 
        return false; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); 
        unordered_set<int> st; 
        for(int i = 0; i<n; i++){
            if(graph[i].size() == 0){
                st.insert(i);
            }
        }
        vector<int> vis(n, 0); 
        vector<int> pathVis(n, 0);
        for(int i = 0; i<n; i++){
            if(dfs(i, vis, pathVis, graph)){ // cycle found 
                continue; 
            }
            else {
                st.insert(i); 
            }
        }
        vector<int> res (st.begin(), st.end()); 
        sort(res.begin(), res.end()); 
        return res; 
    }
};
int main() {
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    Solution sol;
    vector<int> result = sol.eventualSafeNodes(graph);
    cout << "Eventual Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}