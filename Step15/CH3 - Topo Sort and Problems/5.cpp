#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int node : adj[i]) {
                indegree[node]++;
            }
        }
        vector<int> topo;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (int adjacent : adj[node]) {
                indegree[adjacent]--;
                if (indegree[adjacent] == 0) {
                    q.push(adjacent);
                }
            }
        }
        if(topo.size() != numCourses) return {}; // If topo sort doesn't include all nodes, there is a cycle
        return topo; 
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