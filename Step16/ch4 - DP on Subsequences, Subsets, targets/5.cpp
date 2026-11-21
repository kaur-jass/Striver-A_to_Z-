#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int solve(int idx, int target, vector<int>& nums) {
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2; // Two ways to form target 0 with first element being 0
            if(target == 0 || target == nums[0]) return 1; // One way to form target 0 or target equal to first element
            return 0; // No valid subset can be formed
        }
        if(target<0) return 0; // If target becomes negative, no valid subset can be formed
        if(dp[idx][target] != -1) return dp[idx][target]; // Return the stored result if already computed
        int not_take = solve(idx - 1, target, nums); // Exclude the current element
        int take = 0; 
        if(nums[idx] <= target) take = solve(idx - 1, target - nums[idx], nums); // Include the current element if it doesn't exceed the target
        return dp[idx][target] = take + not_take; // Store and return the result
    }
public:
    int count(vector<int>& nums, int diff) {
        int n = nums.size();
        int s = 0; 
        for(int x : nums) s += x; // Calculate the total sum of elements in nums
        int target = (s + diff) / 2; // Calculate the target sum
        if(s < diff || (s + diff) % 2 != 0) return 0; // If the sum is odd, it's impossible to split into two equal subsets
        dp.resize(n, vector<int>(target + 1, -1)); // Initialize dp array with -1
        return solve(n - 1, target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 1, 2, 3};
    int diff = 1;
    Solution obj;
    cout << "Number of subsets with the given difference: " << obj.count(nums, diff) << endl;
    return 0;
}
