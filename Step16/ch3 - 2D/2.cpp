#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp; 
    int solve(int m, int n){
        // Base Case 
        if(m == 0 && n == 0) return 1; 
        if(m<0 || n<0) return 0; 
        if(dp[m][n] != -1) return dp[m][n]; 
        dp[m][n] = solve(m-1, n) + solve(m, n-1); 
        return dp[m][n]; 
    }
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return solve (m-1, n-1); 
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    Solution obj;
    cout << obj.uniquePaths(m, n) << endl;

    return 0;
}