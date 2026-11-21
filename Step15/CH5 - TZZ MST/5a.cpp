#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

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
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &edges) {

        DisjointSet ds(n);

        int cntExtras = 0;

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int cntC = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i)
                cntC++;
        }

        int ans = cntC - 1;

        if (cntExtras >= ans)
            return ans;

        return -1;
    }
};

int main() {

    int n = 6;

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3}
    };

    Solution obj;

    cout << "Minimum operations required = "
         << obj.makeConnected(n, edges) << endl;

    return 0;
}