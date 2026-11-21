#include<bits/stdc++.h>
using namespace std; 
//function to return BFS of a given graph 
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    vis[0] = 1; 
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1; 
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Run BFS from node 0
    vector<int> result = bfsOfGraph(V, adj);

    // Print traversal
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
    