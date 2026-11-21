// Fibonacci Number using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int n;
        vector<int> dp;
    public:
        Solution(int n) : n(n), dp(n + 1, -1) {} // constructor to initialize n and dp vector (initializer list)
        int fib(int n) {
            if(n <= 1) return n;
            dp[0] = 0; 
            dp[1] = 1; 
            // using tabulation
            for(int i = 2; i <= n; i++){ 
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
}; 

int main(){
    int n; 
    cout << "Enter the value of n: ";
    cin >> n;
    Solution obj(n);
    cout << "The fibonacci of n is : " << obj.fib(n) << endl;
    return 0;
}