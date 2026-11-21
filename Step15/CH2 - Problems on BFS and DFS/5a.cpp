#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;

        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, adj, vis))
                    return true;
            }
            else if (adjacentNode != parent) {
                return true; // cycle detected
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

// Driver Code
int main() {
    int V = 5;
    vector<int> adj[V];

    // Example graph (cycle present)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // cycle edge
    adj[1].push_back(4);

    Solution obj;
    if (obj.isCycle(V, adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}