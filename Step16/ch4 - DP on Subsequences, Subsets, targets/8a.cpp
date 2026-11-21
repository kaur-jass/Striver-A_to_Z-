#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp; 
    int solve(int idx, vector<int>& nums, int target){
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2; // Two ways to form target 0 with first element being 0
            if(target == 0 || target == nums[0]) return 1; // One way to form target 0 or target equal to first element
            return 0; // No valid subset can be formed
        }
        if(target<0) return 0; // If target becomes negative, no valid subset can be formed
        if(dp[idx][target] != -1) return dp[idx][target]; // Return the stored result if already computed
        int not_take = solve(idx - 1, nums, target); // Exclude the current element
        int take = 0; 
        if(nums[idx] <= target) take = solve(idx - 1, nums, target - nums[idx]); // Include the current element if it doesn't exceed the target
        return dp[idx][target] = take + not_take; // Store and return the result
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum - target < 0 || (sum - target) % 2 != 0) return 0; // If the sum is less than the target or the difference is odd, return 
        int newTarget = (sum - target) / 2; // Calculate the new target for the subset sum problem
        dp.assign(n, vector<int>(newTarget + 1, -1)); // Initialize
        return solve(n-1, nums, newTarget); // Call the recursive function with the last index and the adjusted target
    }
};

int main(){
    int n, target; 
    cin >> n >> target; 
    vector<int> nums(n); 
    for(int i=0; i<n; i++) cin >> nums[i]; 
    Solution obj; 
    cout << obj.findTargetSumWays(nums, target) << endl; 
    return 0; 
}