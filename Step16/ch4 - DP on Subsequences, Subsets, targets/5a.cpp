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
    int count(vector<int>& nums, int diff) {
        int n = nums.size();
        int s = 0;
        for(int x : nums) s += x; // Calculate the total sum of elements in
        int target = (s + diff) / 2; // Calculate the target sum
        if(s < diff || (s + diff) % 2 != 0) return 0; // If the sum is odd, it's impossible to split into two equal subsets 
        dp.resize(n, vector<int>(target + 1, 0)); // Initialize dp array with -1
        if(nums[0] == 0) dp[0][0] = 2; // Two ways to form target 0 with first element being 0
        else dp[0][0] = 1; // One way to form target 0
        if(nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1; // Base case: if the first element is less than or equal to target, mark it as achievable
        return solve(target, nums);
    }
}; 

int main(){
    vector<int> nums = {1,1,2,3};
    int diff = 1;
    Solution obj;
    cout << "Number of subsets with the given difference: " << obj.count(nums, diff) << endl;
    return 0;
}
