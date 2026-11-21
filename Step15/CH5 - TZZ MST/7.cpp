#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size(); 
        DisjointSet ds(n);
        vector<vector<string>> mergedMail(n); 
        unordered_map<string, int> mp; 
        for(int i = 0; i<n; i++){
            for (int j = 1; j < accounts[i].size(); j++) {
                    string email = accounts[i][j];

                    if (mp.find(email) == mp.end()) {
                        mp[email] = i;
                    } else {
                        ds.unionBySize(i, mp[email]);
                    }
                }
        }
        for(auto &it : mp){
            string e = it.first; 
            int ac = it.second; 
            mergedMail[ds.findUPar(ac)].push_back(e);
        }
        for(int i = 0; i<mergedMail.size(); i++) sort(mergedMail[i].begin(), mergedMail[i].end()); 
        vector<vector<string>> ans; 
        for(int i = 0; i<n; i++){
            if(mergedMail[i].empty()) continue; 
            vector<string> temp; 
            temp.push_back(accounts[i][0]);
            for(int j = 0;j<mergedMail[i].size(); j++){
                temp.push_back(mergedMail[i][j]); 
            }
            ans.push_back(temp); 
        }
        return ans; 
    }
};

int main()
{
    Solution sol;

    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    vector<vector<string>> ans = sol.accountsMerge(accounts);

    cout << "Merged Accounts:\n\n";

    for (auto &account : ans)
    {
        for (auto &str : account)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}