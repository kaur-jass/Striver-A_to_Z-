#include<bits/stdc++.h>
using namespace std; 
class Solution {
vector<int> dp, hash;
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, 1);
        hash.resize(n+1, 0);
        int lastIndex = 0;
        int maxi = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(nums[i]%nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
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
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = sol.largestDivisibleSubset(nums);
    cout << "Largest Divisible Subset: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}