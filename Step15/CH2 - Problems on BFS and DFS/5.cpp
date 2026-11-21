#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool detect(int node, vector<int> adj[], int vis[]) {
            vis[node] = 1; // Mark the current node as being visited
            queue<pair<int, int>> q; // Queue to store (current node, parent node)
            q.push({node, -1}); // Start with the initial node and no parent
            while(!q.empty()) {
                int curr = q.front().first; // Current node
                int parent = q.front().second; // Parent node
                q.pop();
                
                for(int adjNode : adj[curr]) {
                    if(!vis[adjNode]) {
                        vis[adjNode] = 1; // Mark neighbor as being visited
                        q.push({adjNode, curr}); // Add neighbor to the queue with current node as parent
                    } else if(adjNode != parent) {
                        return true; // A cycle is detected
                    }
                }
            }
            return false;
        }
    public:
        bool isCycle(int V, vector<int> adj[]) {
            int vis[V] = {0};
            
            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    if(detect(i,adj, vis)) {
                        return true; // Cycle detected
                    }
                }
            } 
            return false; // No cycle detected
        }
};
int main() {
    Solution s;
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph
    
    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[2].push_back(3);
    adj[3].push_back(2);
    
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    // Uncomment the following lines to create a cycle
    // adj[4].push_back(1);
    // adj[1].push_back(4);
    
    bool hasCycle = s.isCycle(V, adj);
    
    if(hasCycle) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }
    
    return 0;
}