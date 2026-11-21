#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll; 
    int countPaths(int n, vector<vector<int>>& roads) {
        // build the graph 
        vector<pair<int, int>> adj[n]; 
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0]; 
            int v = roads[i][1]; 
            int t = roads[i][2]; 
            adj[u].push_back({v, t}); 
            adj[v].push_back({u, t}); 
        }
        priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
        vector<ll> time(n, LLONG_MAX); 
        vector<ll> ways(n, 0); 
        time[0] = 0; 
        ways[0] = 1; 
        pq.push({0, 0}); 
        while(!pq.empty()){
            ll timeq = pq.top().first; 
            ll node = pq.top().second; 
            pq.pop(); 
            if(timeq > time[node]) continue;
            for(auto it : adj[node]){
                ll adjNode = it.first; 
                ll t = it.second; 
                if(timeq + t < time[adjNode]){
                    time[adjNode] = timeq + t ; 
                    ways[adjNode] = ways[node] % mod; 
                    pq.push({time[adjNode], adjNode}); 
                }
                else if(timeq + t == time[adjNode]) ways[adjNode] = (ways[adjNode] + ways[node]) % mod; 
            }
        }
        return (int)ways[n-1]; 
    }
};
int main() {
    Solution obj;

    int n = 7;
    vector<vector<int>> roads = {
        {0,6,7},
        {0,1,2},
        {1,2,3},
        {1,3,3},
        {6,3,3},
        {3,5,1},
        {6,5,1},
        {2,5,1},
        {0,4,5},
        {4,6,2}
    };

    cout << obj.countPaths(n, roads) << endl;

    return 0;
}