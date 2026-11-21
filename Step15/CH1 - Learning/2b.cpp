#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;   // n = nodes, m = edges

    // adjacency list: (neighbor, weight)
    vector<pair<int,int>> adj[n + 1];

    // input edges
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        // For UNDIRECTED graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});

        // For DIRECTED graph (use this instead)
        // adj[u].push_back({v, wt});
    }

    // Print adjacency list (for debugging)
    cout << "Adjacency List:\n";
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(auto it : adj[i]) {
            cout << "(" << it.first << "," << it.second << ") ";
        }
        cout << "\n";
    }

    return 0;
} 