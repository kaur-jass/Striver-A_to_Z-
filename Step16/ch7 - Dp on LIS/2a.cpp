#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dp, hash;
    public:
        vector<int> lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp.resize(n+1, 1);
            hash.resize(n+1, 0);
            int lastIndex = 0;
            int maxi = 1;
            for(int i = 0; i < n; i++) {
                hash[i] = i;
                for(int prev = 0; prev < i; prev++) {
                    if(nums[i] > nums[prev] && dp[i] < 1 + dp[prev]) {
                        dp[i] = max(dp[i], 1 + dp[prev]);
                        hash[i] = prev;
                    }
                }
                if(dp[i] > maxi) {
                    maxi = dp[i];
                    lastIndex = i;
                }
            }
            vector<int> temp;
            temp.push_back(nums[lastIndex]);
            while(lastIndex != hash[lastIndex]) {
                lastIndex = hash[lastIndex];
                temp.push_back(nums[lastIndex]);
            }
            reverse(temp.begin(), temp.end());
            return temp;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}