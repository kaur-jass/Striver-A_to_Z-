#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int solve(int m, int n){
        vector<int> prev; 
        prev.resize(n, 0);
        for(int i = 0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }
                int up  = 0;
                if(i>0) up = prev[j];
                int left = 0;
                if(j>0) left  = curr[j-1];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
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