#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<unordered_map<int, int>> dp; 
    int solve(int idx, vector<int>& nums, int target){
        if(idx == 0){
            int ways = 0; 
            if(target == +nums[0]) ways++; 
            if(target == -nums[0]) ways++; 
            return ways; 
        }
        if(dp[idx].find(target) != dp[idx].end()) return dp[idx][target]; 
        int positive = solve(idx-1, nums, target-nums[idx]); 
        int negative = solve(idx-1, nums, target+nums[idx]); 
        return dp[idx][target] = positive+negative; 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n); 
        return solve(n-1, nums, target);
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