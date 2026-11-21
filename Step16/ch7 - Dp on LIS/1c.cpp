#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dp;
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp.resize(n+1, 1);
            for(int i = 0; i < n; i++) {
                for(int prev = 0; prev < i; prev++) {
                    if(nums[i] > nums[prev]) {
                        dp[i] = max(dp[i], 1 + dp[prev]);
                    }
                }
            }
            return dp[n-1];
        }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}