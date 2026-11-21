#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> parent, size; 
public:
    int findUPar(int node){
        if(parent[node] == node) return node; 
        return parent[node] = findUPar(parent[node]); 
    }
    void unionBySize(int u, int v){
        int up = findUPar(u); 
        int vp = findUPar(v); 
        if(up == vp) return; 
        if(size[up]<size[vp]){
            parent[up] = vp; 
            size[vp] += size[up]; 
        }
        else{
            parent[vp] = up; 
            size[up] += size[vp]; 
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); 
        parent.resize(n+1, 0); 
        size.resize(n+1, 1); 
        for(int i = 0; i<n; i++) parent[i] = i; 
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unionBySize(i, j); 
                }
            }
        }
        int ans = 0; 
        for(int i = 0; i<n; i++){
            if(findUPar(i) == i) ans++;  // Path compression is not happened for all the nodes while calculating... so need to use findUPar instaed of parent[i]; 
        }
        return n-ans; 
    }
};

int main(){
    Solution obj; 
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}; 
    cout<<obj.removeStones(stones); 
    return 0; 
}
