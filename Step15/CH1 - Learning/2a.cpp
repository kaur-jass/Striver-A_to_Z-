#include<bits/stdc++.h>
using namespace std;
// adjacency list for undirected graph
// time complexity: O(n + m)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // this statement will be removed in case of directed graph
        // in case of directed graph, time complexity will be O(E) as we are only adding one edge to the adjacency list
    }
    return 0;
}