#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int solve(int target, vector<int>& nums) { 
        int n = nums.size();
        for(int i = 1; i < n; i++){
            for(int t = 1; t<=target; t++){
                int not_take = dp[i-1][t]; // Exclude the current element
                int take = 0; 
                if(nums[i] <= t) take = dp[i-1][t - nums[i]]; // Include the current element if it doesn't exceed the target
                dp[i][t] = take + not_take; // Store and return the result
            }
        }
        return dp[n-1][target];
    }
public:
    int count(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<int>(target + 1, 0)); // Initialize dp array with -1
        for(int i = 0; i < n; i++) dp[i][0] = 1; // Base case: target sum of 0 is always achievable
        if(nums[0] <= target) dp[0][nums[0]] = 1; // Base case: if the first element is less than or equal to target, mark it as achievable
        return solve(target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 5, 11, 5};
    int target = 11;
    Solution obj;
    cout << "Number of subsets with the given target: " << obj.count(nums, target) << endl;
    return 0;
}
