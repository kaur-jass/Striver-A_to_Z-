#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool func(int node, int dest, vector<int> &ans, vector<int> &res){
            res.push_back(node); 
            if(node == dest){
                return true; 
            }
            for(int i = 0;i<ans.size(); i++){
                if(ans[i] == node){
                    if(func(i, dest, ans, res)) return true; 
                }
            }
            res.pop_back(); 
            return false; 
        }
        vector<int> Dijsktra(vector<vector<int>> &edges, int src, int dest, int n){
            // Build the graph 
            vector<pair<int, int>> adj[n]; 
            for(int i = 0; i<edges.size(); i++){
                int u = edges[i][0]; 
                int v = edges[i][1]; 
                int wt = edges[i][2]; 
                adj[u].push_back({v,wt}); 
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, 1e9); 
            vector<int> ans(n, -1); 
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
                        ans[v] = node; 
                        dist[v] = dis + wt;  
                        pq.push({dist[v], v}); 
                    }
                }
            }
            vector<int> res; 
            bool a = func(src, dest, ans, res); 
            if(a){
                return res; 
            }
            return {-1}; 
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