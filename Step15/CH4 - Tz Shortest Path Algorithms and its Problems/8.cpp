#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1]; 
        for(int i = 0; i<times.size(); i++){
            int u = times[i][0]; 
            int v = times[i][1]; 
            int ct = times[i][2]; 
            adj[u].push_back({v,ct}); 
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, k}); 
        vector<int> time(n+1,1e9); 
        time[k] = 0; 
        while(!pq.empty()){
            auto i = pq.top(); 
            pq.pop(); 
            int t = i.first; 
            int node = i.second; 
            for(auto it : adj[node]){
                int adjNode = it.first; 
                int newt = it.second + t; 
                if(newt<time[adjNode]){
                    pq.push({newt, adjNode});
                    time[adjNode] = newt;
                }
            }
        }
        int maxi = INT_MIN; 
        for(int i = 1; i<=n; i++){
            maxi = max(maxi, time[i]); 
        }
        return maxi == 1e9 ? -1 : maxi; 
    }
};
int main() {
    Solution obj;

    int n = 4;
    int k = 2;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    cout << "Network Delay Time = "
         << obj.networkDelayTime(times, n, k)
         << endl;

    return 0;
}