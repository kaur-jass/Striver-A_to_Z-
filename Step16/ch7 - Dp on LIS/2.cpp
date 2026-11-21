#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int lis(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int skip = lis(nums, i + 1, prev);
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) take = 1 + lis(nums, i + 1, i);
        return dp[i][prev + 1] = max(take, skip);
    }

public:
    vector<int> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n + 1, -1));
        int length = lis(nums, 0, -1);
        // Reconstruct LIS
        vector<int> ans;
        int i = 0, prev = -1;
        while (i < n) {
            int skip = lis(nums, i + 1, prev);
            int take = -1;
            if (prev == -1 || nums[i] > nums[prev])
                take = 1 + lis(nums, i + 1, i);
            if (take >= skip) {
                ans.push_back(nums[i]);
                prev = i;
            }
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> lis = sol.lengthOfLIS(nums);
    cout << "LIS: ";
    for (int x : lis)
        cout << x << " ";
    cout << endl;
    return 0;
}