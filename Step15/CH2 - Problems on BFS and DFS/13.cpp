#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &colors){ 
        for(auto it: graph[node]){
            if(colors[it] == -1) {
                colors[it] = 1 - colors[node]; 
                if(!dfs(it, graph, colors)) return false; 
            }
            else if(colors[it] == colors[node]) return false; 
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> colors(n, -1); 
        for(int i = 0; i<n; i++){
            if(colors[i] == -1){
                colors[i] = 0; 
                if(!dfs(i, graph, colors)) return false; 
            }
        }
        return true; 
    }
};

int main(){
    int n; 
    cin >> n; 
    vector<vector<int>> graph(n); 
    for(int i = 0; i<n; i++){
        int m; 
        cin >> m; 
        graph[i].resize(m); 
        for(int j = 0; j<m; j++) cin >> graph[i][j]; 
    }
    Solution ob; 
    cout << (ob.isBipartite(graph) ? "true" : "false") << endl;
}
