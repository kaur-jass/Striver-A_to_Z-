#include<bits/stdc++.h>
using namespace std;

class Solution {

    // means

    // A vector
    // where each element is an unordered_map<int,int>

    // Visualize it:

    // dp
    // │
    // ├── dp[0] ---> unordered_map
    // │               {
    // │                 0  -> 1
    // │                 5  -> 2
    // │                -3  -> 4
    // │               }
    // │
    // ├── dp[1] ---> unordered_map
    // │               {
    // │                 1  -> 3
    // │                -2  -> 1
    // │               }
    // │
    // └── dp[2] ---> unordered_map
    //                 {
    //                 7  -> 8
    //                 0  -> 5
    //                 }

    vector<unordered_map<int,int>> dp;
    int solve(int idx, int target, vector<int>& nums) {
        if(target == 0) return 1; // Found a subset with the target sum
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2; // Two ways to form target 0 with first element being 0
            if(target == 0 || target == nums[0]) return 1; // One way to form target 0 or target equal to first element
            return 0; // No valid subset can be formed
        }
        if(target<0) return 0; // If target becomes negative, no valid subset can be formed
        if(dp[idx].find(target) != dp[idx].end()) return dp[idx][target]; // Return the stored result if already computed
        int not_take = solve(idx - 1, target, nums); // Exclude the current element
        int take = 0; 
        if(nums[idx] <= target) take = solve(idx - 1, target - nums[idx], nums); // Include the current element if it doesn't exceed the target
        return dp[idx][target] = take + not_take; // Store and return the result
    }
public:
    int count(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n); // Initialize dp array with empty unordered_maps
        return solve(n - 1, target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 5, 11, 5};
    int target = 11;
    Solution obj;
    cout << "Number of subsets with the given target: " << obj.count(nums, target) << endl;
    return 0;
}
