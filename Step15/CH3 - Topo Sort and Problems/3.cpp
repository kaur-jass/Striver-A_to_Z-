#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int node : adj[i]) {
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
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
        if(cnt != V) return false; // If we didn't visit all nodes, there is a cycle
        return true; // If we can perform topological sort, there is no cycle
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(1); // This edge creates a cycle

    Solution obj;
    if (obj.isCycle(V, adj))
        cout << "No Cycle Detected\n";
    else
        cout << "Cycle Detected\n";
    return 0;
}
