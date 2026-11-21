#include<bits/stdc++.h>
using namespace std; 
class Solution{
    public:
        vector<int> Bellmannford(int V, vector<vector<int>> &edges, int s){
            vector<int> dist(V, 1e9); 
            dist[s] = 0; 
            for(int i = 0; i<V; i++){
                for(auto it : edges){
                    int u = it[0]; 
                    int v = it[1]; 
                    int wt = it[2]; 
                    if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt; 
                    }
                }
            }
            // nth relaxation to check negative edge weight cycle 
            for(auto it : edges){
                int u = it[0]; 
                int v = it[1]; 
                int wt = it[2]; 
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    return {-1}; 
                }
            }
            return dist; 
        }
};

int main() {
    Solution obj;

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> ans = obj.Bellmannford(V, edges, source);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative Weight Cycle Detected\n";
    } else {
        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            if (ans[i] == 1e9)
                cout << "INF";
            else
                cout << ans[i];
            cout << endl;
        }
    }

    return 0;
}