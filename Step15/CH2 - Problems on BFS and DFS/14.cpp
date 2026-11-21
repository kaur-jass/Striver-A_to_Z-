#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathVis, vector<int> &st){
        vis[node] = 1;
        pathVis[node] = 1; 
        for(auto it : adj[node]){
            if (!vis[it]){
                if(dfs(it, adj, vis, pathVis, st)) return true; 
            }
            else if(pathVis[it] == 1){ // cycle is found
                return true; 
            }
        }
        pathVis[node] = 0; 
        st.push_back(node); 
        return false; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        // build graph 
        for(auto &p : prerequisites){
            int u = p[0]; 
            int v = p[1];
            adj[v].push_back(u);
        }
        // now coming towards visited array 
        vector<int> vis(numCourses, 0); 
        vector<int> pathVis(numCourses, 0); 
        vector<int> st; 
        for(int i = 0; i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis, st)) return {}; 
            }
        }
        reverse(st.begin(), st.end()); 
        return st; 
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    Solution sol;
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    if (result.empty()) {
        cout << "No valid course order exists." << endl;
    } else {
        cout << "Course order: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}