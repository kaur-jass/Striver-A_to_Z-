#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> Dijsktra(vector<vector<int>> &edges, int src, int dest, int n){
            // Build the graph 
            vector<pair<int, int>> adj[n]; 
            for(int i = 0; i<edges.size(); i++){
                int u = edges[i][0]; 
                int v = edges[i][1]; 
                int wt = edges[i][2]; 
                adj[u].push_back({v,wt}); 
                adj[v].push_back({u,wt}); 
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, 1e9); 
            vector<int> parent(n);
            for(int i = 1; i<=n; i++) parent[i] = i;  
            dist[src] = 0; 
            pq.push({0, src}); 
            while(!pq.empty()){
                int dis = pq.top().first; 
                int node = pq.top().second; 
                pq.pop(); 
                if(dis > dist[node]) continue;
                for(auto it : adj[node]){
                    int v = it.first; 
                    int wt = it.second;
                    if(dis + wt < dist[v]){
                        parent[v] = node; 
                        dist[v] = dis + wt;  
                        pq.push({dist[v], v}); 
                    }
                }
            }
            if(dist[dest] == 1e9) return {-1};
            vector<int> res; 
            int node = dest; 
            while(parent[node] != node){
                res.push_back(node);
                node = parent[node]; 
            }
            res.push_back(node);
            reverse(res.begin(), res.end()); 
            return res; 
        }
};
int main() {
    Solution obj;

    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,1},
        {2,1,2},
        {1,3,1},
        {2,3,5}
    };

    int n = 4;
    int src = 0;
    int dest = 3;

    vector<int> path = obj.Dijsktra(edges, src, dest, n);

    for(int x : path) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}