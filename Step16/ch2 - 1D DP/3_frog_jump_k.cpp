#include<bits/stdc++.h>
using namespace std;

class Solution{  
    vector<int>dp;                // space optimization solution 
public: 
    int n; 
    Solution(int n) : n(n){
        dp.resize(n+1, -1); 
    }
    int frogJump(int n, vector<int> &heights, int k) {
        if(n == 0) return 0; 
        if(dp[n] != -1) return dp[n]; 
        int left = frogJump(n-1, heights, k) + abs(heights[n] - heights[n-1]); 
        int right = INT_MAX;
        int mini = left; 
        for(int i = 2; i<=k; i++){
            if(n-i>=0) right = frogJump(n-i, heights, k) + abs(heights[n] - heights[n-i]);
            mini = min(mini, right); 
        }
        dp[n] = mini; 
        return dp[n];
    }
}; 

int main(){
    cout << "Enter the number of steps: ";
    int n;
    cin >> n;
    cout << "Enter k(steps): "; 
    int k; 
    cin >> k; 
    Solution obj(n); 
    vector<int> heights(n);
    cout << "Enter the heights of the steps: ";
    for(int i = 0; i < n; i++) cin >> heights[i];
    cout << "The minimum energy required to reach the nth step is : " << obj.frogJump(n-1, heights, k) << endl;
    return 0;
} 