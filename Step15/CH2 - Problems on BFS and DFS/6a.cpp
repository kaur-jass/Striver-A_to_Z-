#include<bits/stdc++.h>
using namespace std;
// DETECT A CYCLE IN A DIRECTED GRAPH USING DFS
class Solution {
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {

        vis[node] = 1;
        pathVis[node] = 1;

        // traverse for adjacent nodes
        for(auto it : adj[node]) {

            // when the node is not visited
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }

            // if the node has been previously visited
            // but it has to be visited on the same path
            else if(pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[]) {

        int vis[V] = {0};
        int pathVis[V] = {0};

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis) == true)
                    return true;
            }
        }

        return false;
    }
};


int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(1); // This edge creates a cycle

    Solution obj;
    if (obj.isCyclic(V, adj))
        cout << "Cycle Detected in Directed Graph\n";
    else
        cout << "No Cycle in Directed Graph\n";

    return 0;
}