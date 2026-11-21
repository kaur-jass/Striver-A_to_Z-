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
        // using memoization
        if(n == 0) return 0; 
        int jump1 = frogJump(n-1, heights) + abs(heights[n] - heights[n-1]); // jump from i-1 to i : step 1
        int jump2 = INT_MAX;
        if(n > 1) jump2 = frogJump(n-2, heights)+ abs(heights[n] - heights[n-2]); // jump from i-2 to i : step 2
        dp[n] = min(jump1, jump2);
        return dp[n];
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