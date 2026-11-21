#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> prev, curr;
public:
    bool solve(int target , vector<int>& nums){
        int n = nums.size(); 
        for(int idx = 1; idx<n; idx++){
            curr.assign(target + 1, false); // Initialize curr array with false
            curr[0] = true; // Base case: target sum of 0 is always achievable
            for(int t = 1; t<=target; t++){
                bool not_take = prev[t]; // Exclude the current element
                bool take = false;
                if(nums[idx] <= t) take = prev[t - nums[idx]]; // Include the current element if it doesn't exceed the target
                curr[t] = take || not_take; // Store the result
            }
            prev = curr; // Move current row to previous row for the next iteration
        }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum % 2) return false;
        int target = sum / 2;
        prev.assign(target + 1, false); // Initialize prev array with false    
        prev[0] = true; // Base case: target sum of 0 is always achievable
        if(nums[0] <= target) prev[nums[0]] = true; // Base case: if the first element is less than or equal to target, mark it as achievable
        return solve(target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 5, 11, 5};
    Solution obj;
    if(obj.canPartition(nums)) cout << "Subset with the given target exists." << endl;
    else cout << "No subset with the given target exists." << endl;
    return 0;
}