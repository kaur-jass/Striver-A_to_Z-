#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // course scheduling is actually a cycle detection in a directed graph 
    // if u detect cycle means u cannot finish courses but if there is no cycle that means we can finish courses easily. 
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis){
        vis[node] = 1; 
        for(auto it : adj[node]){
            if(!vis[it]){ // not visited yet
                if(dfs(it, adj, vis)) return true; 
            }
            if(vis[it] == 1) return true;  // cycle found
        }
        vis[node] = 2; // viisted
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        // build graph 
        for(auto &p : prerequisites){
            int u = p[0]; 
            int v = p[1];
            adj[v].push_back(u);
        }
        // now coming towards visited array 
        vector<int> vis(numCourses, 0); 
        for(int i = 0; i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis)) return false; 
            }
        }
        return true; 
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    Solution sol;
    bool result = sol.canFinish(numCourses, prerequisites);
    cout << (result ? "Can finish all courses" : "Cannot finish all courses") << endl;
    return 0;
}