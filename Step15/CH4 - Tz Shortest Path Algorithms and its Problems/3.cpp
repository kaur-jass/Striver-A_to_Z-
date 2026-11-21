#include<bits/stdc++.h>
using namespace std; 

class Solution{
    public:
        vector<int> Dijkstra(vector<vector<int>> &edges, int src, int n){
            // Build the Adj list 
            vector<pair<int, int>> adj[n]; 
            for(int i = 0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1]; 
                int wt = edges[i][2]; 
                adj[u].push_back({v, wt});
            }
            // now i will do it by using priority queue 
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; 
            pq.push({0, src}); 
            vector<int> dist(n, 1e9); 
            dist[src] = 0;
            while(!pq.empty()){
                int dis = pq.top().first; 
                int node = pq.top().second;
                pq.pop(); 
                if(dis > dist[node]) continue; // skipping the outdates nodes just after pop significantly increased TC from 5 seconds to 0.8 seconds.
                for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second; 
                    if(dis + wt < dist[v]){
                        dist[v] = dis + wt; 
                        pq.push({dist[v], v}); 
                    }
                }
            }
            vector<int> ans(n,-1); 
            for(int i = 0; i<n; i++){
                if(dist[i] != 1e9){
                    ans[i] = dist[i]; 
                }
            }
            return ans; 
        }
}; 
int main(){

    Solution obj;

    int n = 6;

    vector<vector<int>> edges = {
        {0,1,2},
        {0,4,1},
        {1,2,3},
        {4,2,2},
        {4,5,4},
        {2,3,6},
        {5,3,1}
    };

    int src = 0;

    vector<int> ans = obj.Dijkstra(edges, src, n);

    cout << "Shortest distances from source " << src << ":\n";

    for(int i=0;i<n;i++){
        cout << i << " -> " << ans[i] << endl;
    }

    return 0;
}