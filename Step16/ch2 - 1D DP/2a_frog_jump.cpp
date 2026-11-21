#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        vector<int> dp; // to store the minimum energy required to reach each step
public:
    int n; 
    Solution(int n) : n(n) {
        dp.resize(n+1, -1); // initialize dp array with -1
    }
    int frogJump(int n, vector<int> &heights) {
        // using tabulation
        dp[0] = 0; // base case: energy required to reach the first step
        for(int i = 1; i <= n; i++){
            int jump1 = dp[i-1] + abs(heights[i] - heights[i-1]); // jump from i-1 to i : step 1
            int jump2 = INT_MAX;
            if(i > 1) jump2 = dp[i-2] + abs(heights[i] - heights[i-2]); // jump from i-2 to i : step 2
            dp[i] = min(jump1, jump2);
        }
        return dp[n-1];
    }
}; 

int main(){
    cout << "Enter the number of steps: ";
    int n;
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the heights of the steps: ";
    for(int i = 0; i < n; i++) cin >> heights[i];
    Solution obj(n);
    cout << "The minimum energy required to reach the nth step is : " << obj.frogJump(n-1, heights) << endl;
    return 0;
}