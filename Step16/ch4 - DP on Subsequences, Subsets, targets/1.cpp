#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> dp;
public:
    bool solve(int idx, int target , vector<int>& nums){
        if(target == 0) return true; // Found a subset with the target sum
        if(idx == 0) return nums[0] == target; // Check if the first element is equal to the target
        if(dp[idx][target] != -1) return dp[idx][target]; // Return the stored result if already computed
        bool not_take = solve(idx - 1, target, nums); // Exclude the current element
        bool take = false;
        if(nums[idx] <= target) take = solve(idx - 1, target - nums[idx], nums); // Include the current element if it doesn't exceed the target
        return dp[idx][target] = take || not_take; // Store and return the result
    }
    bool canPartition(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<int>(target + 1, -1)); // Initialize dp array with -1
        return solve(n - 1, target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 5, 11, 5};
    int target = 11;
    Solution obj;
    if(obj.canPartition(nums, target)) cout << "Subset with the given target exists." << endl;
    else cout << "No subset with the given target exists." << endl;
    return 0;
}