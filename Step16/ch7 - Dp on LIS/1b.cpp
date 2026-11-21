#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> prev, curr;
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            prev.resize(n + 1, 0);
            curr.resize(n + 1, 0);
            prev[0] = 1;
            for(int i = n - 1; i >= 0; i--) {
                for(int prev_ind = i - 1; prev_ind >= -1; prev_ind--) {
                    int len = 0;
                    if(prev_ind == -1 || nums[i] > nums[prev_ind]) {
                        len = 1 + prev[i + 1];
                    }
                    len = max(len, prev[prev_ind + 1]);
                    curr[prev_ind + 1] = len;
                }
                prev = curr;
            }
            return curr[0];
        }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}