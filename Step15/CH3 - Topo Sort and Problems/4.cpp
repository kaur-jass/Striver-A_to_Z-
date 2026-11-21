#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // course scheduling is actually a cycle detection in a directed graph 
    // if u detect cycle means u cannot finish courses but if there is no cycle that means we can finish courses easily. 
    // using topo sort to detect cycle in directed graph
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        stack<int> st;
        // build graph 
        for(auto &p : prerequisites){
            int u = p[0]; 
            int v = p[1];
            adj[v].push_back(u);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int node : adj[i]) {
                indegree[node]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++; 
            
            for (int adjacent : adj[node]) {
                indegree[adjacent]--;
                if (indegree[adjacent] == 0) {
                    q.push(adjacent);
                }
            }
        }
        if(cnt != numCourses) return false; // If we didn't visit all nodes, there is a cycle
        return true; // If we can perform topological sort, there is no cycle
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