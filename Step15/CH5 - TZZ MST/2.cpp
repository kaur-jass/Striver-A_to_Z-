#include<bits/stdc++.h>
using namespace std; 
class Solution{
    public:
        int Prims(int v, vector<vector<int>> adj[]){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
            vector<int> vis(v,0); 
            pq.push({0,0}); // Weight and node
            int sum = 0; 
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop(); 
                int node = it.second; 
                int wt = it.first; 
                if(vis[node] == 1) continue; 
                vis[node] = 1; 
                sum += wt; 
                for(auto it : adj[node]){
                    int adjNode = it[0];
                    int edN = it[1]; 
                    if(!vis[adjNode]){
                        pq.push({edN, adjNode}); 
                    }
                }
            }
            return sum; 
        }
}; 

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int V = 5;
    vector<vector<int>> adj[V];

    // Edge 0 - 1 (2)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    // Edge 0 - 3 (6)
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    // Edge 1 - 2 (3)
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    // Edge 1 - 3 (8)
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    // Edge 1 - 4 (5)
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    // Edge 2 - 4 (7)
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    // Edge 3 - 4 (9)
    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    Solution obj;
    cout << obj.Prims(V, adj);

    return 0;
}