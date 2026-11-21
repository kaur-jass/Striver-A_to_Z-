#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    public:
        int rodcutting(int N, vector<int>& price) {
            dp.assign(N, vector<int>(N+1, 0));
            for(int n = 0; n <= N; n++) {
                dp[0][n] = n * price[0];
            }
            for(int idx = 1; idx < N; idx++) {
                for(int n = 0; n <= N; n++) {
                    int dont_cut = dp[idx-1][n];
                    int cut = INT_MIN;
                    int rod_length = idx + 1;
                    if(rod_length <= n) {
                        cut = price[idx] + dp[idx][n - rod_length];
                    }
                    dp[idx][n] = max(cut, dont_cut);
                }
            }
            return dp[N-1][N];
        }
};

int main(){
    int n; 
    cin >> n; 
    vector<int> price(n); 
    for(int i=0; i<n; i++) cin >> price[i]; 
    Solution obj; 
    cout << obj.rodcutting(n, price) << endl; 
    return 0; 
}
