#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prev, curr;
    int solve(int target, vector<int>& nums) { 
        int n = nums.size();
        for(int i = 1; i < n; i++){
            curr.assign(target + 1, 0); // Initialize curr array with 0
            curr[0] = 1; // Base case: target sum of 0 is always achievable
            for(int t = 1; t<=target; t++){
                int not_take = prev[t]; // Exclude the current element
                int take = 0; 
                if(nums[i] <= t) take = prev[t - nums[i]]; // Include the current element if it doesn't exceed the target
                curr[t] = take + not_take; // Store and return the result
            }
            prev = curr; // Move current row to previous row for the next iteration
        }
        return prev[target];
    }
public:
    int count(vector<int>& nums, int target) {
        int n = nums.size();
        prev.resize(target + 1, 0); // Initialize prev and curr arrays with 0
        prev[0] = 1; // Base case: target sum of 0 is always achievable
        if(nums[0] <= target) prev[nums[0]] = 1;
        prev[0] = 1; // Base case: target sum of 0 is always achievable
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
