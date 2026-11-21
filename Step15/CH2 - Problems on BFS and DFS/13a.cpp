#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int start, int V, vector<int> adj[], vector<int>& color) {

        queue<int> q;
        q.push(start);

        color[start] = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {

                // If adjacent node is not colored
                if(color[it] == -1) {

                    color[it] = !color[node];
                    q.push(it);
                }

                // Adjacent node has same color
                else if(color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[]) {

        vector<int> color(V, -1);

        for(int i = 0; i < V; i++) {

            if(color[i] == -1) {

                if(!check(i, V, adj, color))
                    return false;
            }
        }

        return true;
    }
};

int main() {
    int V;
    cin >> V;

    vector<int> adj[V];

    for(int i = 0; i < V; i++) {
        int m;
        cin >> m;
        adj[i].resize(m);
        for(int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    Solution ob;
    cout << (ob.isBipartite(V, adj) ? "true" : "false") << endl;

    return 0;
}