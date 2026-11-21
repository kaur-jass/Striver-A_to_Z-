#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp;
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp.resize(n+1, vector<int>(n + 1, 0));
            for(int i = n - 1; i >= 0; i--) {
                for(int prev = i - 1; prev >= -1; prev--) {
                    int len = 0;
                    if(prev == -1 || nums[i] > nums[prev]) {
                        len = 1 + dp[i + 1][i + 1];
                    }
                    len = max(len, dp[i + 1][prev + 1]);
                    dp[i][prev + 1] = len;
                }
            }
            return dp[0][0];
        }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}