#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dp; 
private:
    int climb(int x,vector<int> &dp){                     
        if (x <= 1) return 1;  
        if(dp[x] != -1) return dp[x];              // check if already computed OR FETCHING FROM MEMOIZATION TABLE  
        dp[x] = climb(x-1, dp) + climb(x-2, dp);   // ensure that x-1 and x-2 r computed first 
        return dp[x]; 
    }
public:
    int climbStairs(int n) {
        dp.resize(n+1, -1); 
        dp[0] = 1; 
        dp[1] = 1; 
        return climb(n, dp); 
    }
};

int main (){
    int n; 
    cout << "Enter the value of n: ";
    cin >> n;
    Solution obj;
    cout << "The number of ways to climb stairs is : " << obj.climbStairs(n) << endl;
    return 0;
}