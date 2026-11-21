#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int src) {
        int n = edges.size();
        vector<int> adj[n];
        for(auto it : edges){ // Building the adjacency list
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(n, 1e9); // Initialize distances with a large value
        dist[src] = 0; // Distance to the source is 0
        queue<pair<int, int>> q; // Queue to store (node, distance)
        q.push({src,0}); // Start BFS from the source node
        while(!q.empty()){
            int node = q.front().first; 
            int dis = q.front().second; 
            q.pop(); 
            for(auto it : adj[node]){ // Explore neighbors
                if(dis + 1 < dist[it]){ // If a shorter path is found
                    dist[it] = dis + 1; // Update distance
                    q.push({it, dis + 1}); // Add neighbor to the queue with updated distance
                }
            }
        }
        vector<int> result(n, -1); // Initialize result with -1 for unreachable nodes
        for(int i = 0; i < n; i++){
            if(dist[i] != 1e9){ // If the node is reachable
                result[i] = dist[i]; // Update result with the shortest distance
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    int src = 0;
    Solution sol;
    vector<int> result = sol.shortestPath(edges, src);
    cout << "Shortest distances from source node " << src << ": ";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }
    return 0;
}