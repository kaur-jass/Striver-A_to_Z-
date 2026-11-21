#include<bits/stdc++.h>
using namespace std; 

class Solution {
    vector<vector<int>> dp;
    int lis(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) return 0; 
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int len = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            len = 1 + lis(nums, i + 1, i);
        }
        len = max(len, lis(nums, i + 1, prev));
        return dp[i][prev + 1] = len;
    }

    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp.resize(n, vector<int>(n + 1, -1));
            return lis(nums, 0, -1);
        }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}