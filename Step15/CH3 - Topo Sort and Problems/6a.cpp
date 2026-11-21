#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>>& graph){
        vis[node] = 1; 
        pathVis[node] = 1; 
        check[node] = 1; 
        for(auto it : graph[node]){
            if (!vis[it]){
                if(dfs(it, vis, pathVis, check, graph)) return true; 
            }
            else if(pathVis[it] == 1){ // cycle found
                return true; 
            }
        }
        check[node] = 0; 
        pathVis[node] = 0; 
        return false; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> vis(n, 0); 
        vector<int> pathVis(n, 0);
        vector<int> check(n,0); 
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, graph); 
            }
        }
        vector<int> ans; 
        for(int i = 0; i<n; i++){
            if(check[i] == 0){
                ans.push_back(i); 
            }
        }
        return ans; 
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