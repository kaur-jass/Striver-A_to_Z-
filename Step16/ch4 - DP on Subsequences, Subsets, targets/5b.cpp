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
    int count(vector<int>& nums, int diff) {
        int n = nums.size();
        int s = 0;
        for(int x : nums) s += x; // Calculate the total sum of elements in nums
        int target = (s + diff) / 2; // Calculate the target sum
        if(s < diff || (s + diff) % 2 != 0) return 0; // If the sum is odd, it's impossible to split into two equal subsets
        prev.resize(target + 1, 0); // Initialize prev and curr arrays with 0
        if(nums[0] == 0) prev[0] = 2; // Two ways to form target 0 with first element being 0
        else prev[0] = 1; // One way to form target 0
        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1; // Base case: if the first element is less than or equal to target, mark it as achievable
        return solve(target, nums);
    }
}; 

int main(){
    vector<int> nums = {1, 1, 2, 3};
    int diff = 1;
    Solution obj;
    cout << "Number of subsets with the given difference: " << obj.count(nums, diff) << endl;
    return 0;
}
