#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i=0;i<n;i++) parent[i] = i;
        }

        int findParent(int node){
            if(node == parent[node]) return node; 
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            u = findParent(u);
            v = findParent(v);
            if(u == v) return; 
            if(size[u] < size[v]){
                parent[u] = v; 
                size[v] += size[u];
            }else{
                parent[v] = u; 
                size[u] += size[v];
            }
        }
}; 

class Solution {

    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
            int n = accounts.size();
            DisjointSet ds(n); 
            unordered_map<string, int> mapMailNode;
            for(int i = 0; i<n; i++){
                for(int j = 1; j<accounts[i].size(); j++){
                    // Merge accounts based on email addresses
                    string email = accounts[i][j];
                    if(mapMailNode.find(email) == mapMailNode.end()){
                        mapMailNode[email] = i;
                    }else{
                        ds.unionBySize(i, mapMailNode[email]);
                    }
                }
            }
            // Create a mapping of parent node to its emails
            vector<string> mergedMail[n];
            for(auto it : mapMailNode){
                string email = it.first; 
                int node = it.second; 
                mergedMail[ds.findParent(node)].push_back(email);
            }
            // Prepare the final result
            vector<vector<string>> result;
            for(int i = 0; i<n; i++){
                if(!mergedMail[i].empty()){
                    sort(mergedMail[i].begin(), mergedMail[i].end());
                    mergedMail[i].insert(mergedMail[i].begin(), accounts[i][0]);
                    result.push_back(mergedMail[i]);
                }
            }
            return result;
        }
}; 

int main(){
    int n; 
    cin >> n; 
    vector<vector<string>> accounts(n);
    for(int i = 0; i<n; i++){
        int m; 
        cin >> m; 
        accounts[i].resize(m);
        for(int j = 0; j<m; j++){
            cin >> accounts[i][j];
        }
    }
    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for(auto it : ans){
        for(auto email : it){
            cout << email << " ";
        }
        cout << endl;
    }
    return 0; 
}