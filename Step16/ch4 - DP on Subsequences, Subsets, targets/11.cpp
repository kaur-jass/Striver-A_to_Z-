#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int solve(int idx, int n, vector<int>& price){
        if(idx==0) return n*price[0]; 
        if(dp[idx][n]!=-1) return dp[idx][n]; 
        int dont_cut = solve(idx-1, n, price); 
        int cut = INT_MIN; 
        int rod_length = idx+1; 
        if(rod_length<=n) cut = price[idx] + solve(idx, n-rod_length, price); 
        return dp[idx][n] = max(cut, dont_cut); 
    }
    public:
        int rodcutting(int N, vector<int>& price) {
            dp.assign(N, vector<int>(N+1, -1));
            return solve(N-1, N, price);
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
