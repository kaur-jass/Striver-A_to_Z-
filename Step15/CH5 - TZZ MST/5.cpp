#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<int> parent, size; 
    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // ensure there are atleast n-1 connections to connect n nodes 
        if(connections.size() < n-1) return -1;
        parent.resize(n+1, 0); 
        size.resize(n+1, 1); 
        for(int i=0; i<n; i++) parent[i] = i; 
        for(auto &it : connections)  unionBySize(it[0], it[1]);
        int components = 0; 
        for(int i = 0; i<n; i++){
            if(parent[i] == i) components++; 
        }
        return components-1; 
    }
};

int main() {
    int n = 6;

    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 2},
        {1, 3}
    };

    Solution sol;

    cout << "Minimum operations needed: "
         << sol.makeConnected(n, connections) << endl;

    return 0;
}