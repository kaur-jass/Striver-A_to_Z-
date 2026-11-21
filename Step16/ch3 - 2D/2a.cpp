#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp; 
    int solve(int m, int n){
        // Base Case 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int up  = 0;
                if(i>0) up = dp[i-1][j];
                int left = 0;
                if(j>0) left  = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return solve (m, n); 
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    Solution obj;
    cout << obj.uniquePaths(m, n) << endl;

    return 0;
}