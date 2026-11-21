#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph with weights
    // time complexity: O(n)
    // space complexity: O(n^2)
    int adj[n+1][m+1];
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;  // this statement will be removed in case of directed graph
    }
    return 0;
}
