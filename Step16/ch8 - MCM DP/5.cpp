#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp; 
    int cut(int i, int j, vector<int>& cuts){
        //Base Case 
        if(j-i<=1) return 0; 
        if(dp[i][j] != -1) return dp[i][j]; 
        long long t_cost = INT_MAX; 
        for(int k = i+1; k<j; k++){ // dont include i and j as they are representing boundaries 
            long long cost = cuts[j] - cuts[i] + cut(i, k, cuts) + cut(k, j, cuts);
            t_cost = min(cost, t_cost);
        }
        return dp[i][j] = (int)t_cost; 
    }
public:
    int minCost(int n, vector<int>& cuts) {
        //dp[i][j]=minimum cost to cut the segment [cuts[i],cuts[j]]
        sort(cuts.begin(), cuts.end());  
        cuts.insert(cuts.begin(), 0); 
        cuts.push_back(n); 
        int m = cuts.size();
        dp.resize(m, vector<int>(m, -1));
        return cut(0, m-1, cuts); 
    }
};


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cuts(m);
    for(int i = 0; i < m; i++)
        cin >> cuts[i];
    Solution obj;
    cout << obj.minCost(n, cuts) << endl;
    return 0;
}