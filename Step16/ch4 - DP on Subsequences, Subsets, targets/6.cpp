#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp; 
    int solve(int m, int n,vector<int>& s, vector<int>& g){
        if(m < 0 || n < 0) return 0; 
        if(dp[m][n] != -1) return dp[m][n]; 
        // condition satisfied
        if(s[m] >= g[n]){
            dp[m][n] = max(solve(m-1, n, s, g), 1+solve(m-1, n-1, s, g)); 
        }
        else{
            dp[m][n] = max(solve(m-1, n, s, g), solve(m, n-1, s, g)); 
        }
        return dp[m][n]; 
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = s.size(); 
        int n = g.size(); 
        dp.resize(m+1, vector<int>(n+1, -1)); 
        sort(s.begin(), s.end()); 
        sort(g.begin(), g.end()); 
        return solve(m-1, n-1, s, g); 
    }
};

int main(){
    vector<int> g = {1, 2, 3}; 
    vector<int> s = {1, 1}; 
    Solution obj; 
    cout << "Maximum number of content children: " << obj.findContentChildren(g, s) << endl; 
    return 0; 
}