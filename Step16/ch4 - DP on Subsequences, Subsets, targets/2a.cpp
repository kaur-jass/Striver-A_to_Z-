#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<bool>> dp;
public:
    bool solve(int target , vector<int>& nums){
        int n = nums.size(); 
        for(int idx = 1; idx<n; idx++){
            for(int t = 1; t<=target; t++){
                bool not_take = dp[idx-1][t]; // Exclude the current element
                bool take = false;
                if(nums[idx] <= t) take = dp[idx-1][t - nums[idx]]; // Include the current element if it doesn't exceed the target
                dp[idx][t] = take || not_take; // Store the result
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int x : nums) sum += x;
        if(sum % 2) return false;
        int target = sum / 2;
        dp.resize(n, vector<bool>(target + 1, false)); // Initialize dp array with false
        for(int i = 0; i < n; i++) dp[i][0] = true; // Base case: target sum of 0 is always achievable
        if(nums[0] <= target) dp[0][nums[0]] = true; // Base case: if the first element is less than or equal to target, mark it as achievable
        return solve(target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 5, 11, 5};
    int target = 11;
    Solution obj;
    if(obj.canPartition(nums)) cout << "Subset with the given target exists." << endl;
    else cout << "No subset with the given target exists." << endl;
    return 0;
}   