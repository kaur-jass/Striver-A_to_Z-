#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> parent, size; 
public:
    int findUPar(int node){
        if(parent[node] == node) return node; // Found the ultimate parent.
        return parent[node] = findUPar(parent[node]); // Path compression.
    }

    void unionBySize(int u, int v){
        int up = findUPar(u);
        int vp = findUPar(v);
        if(up == vp) return; // Already in the same component.

        if(size[up] < size[vp]){
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
        if(n == 1) return 0;

        int maxRow = 0, maxCol = 0;

        for(int i = 0; i < n; i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        parent.resize(maxRow + maxCol + 2, 0);
        size.resize(maxRow + maxCol + 2, 1);

        // Initialize each node as its own parent.
        for(int i = 0; i < maxRow + maxCol + 2; i++) parent[i] = i;

        for(int i = 0; i < n; i++){
            int rowNode = stones[i][0];
            int colNode = stones[i][1] + maxRow + 1; // Shift column indices to avoid overlap.
            unionBySize(rowNode, colNode);
        }

        int components = 0;

        // Count connected components that actually contain stones.
        for(int i = 0; i < maxRow + maxCol + 2; i++){
            if(parent[i] == i && size[i] > 1) components++;
        }

        return n - components;
    }
};

int main(){
    Solution obj; 
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}; 
    cout<<obj.removeStones(stones); 
    return 0; 
}
