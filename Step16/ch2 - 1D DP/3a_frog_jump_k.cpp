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
        dp[0] = 0; 
        for(int i = 1; i<n; i++){
            int left = dp[i-1] + abs(heights[i] - heights[i-1]); 
            int right = INT_MAX; 
            int mini = left; 
            for(int j = 2; j<=k; j++){
                if(i-j>=0){
                    right = dp[i-j] + abs(heights[i] - heights[i-j]); 
                    mini = min(right, mini); 
                } 
            }
            dp[i] = mini; 
        }
         return dp[n-1]; 
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
    cout << "The minimum energy required to reach the nth step is : " << obj.frogJump(n, heights, k) << endl;
    return 0;
} 