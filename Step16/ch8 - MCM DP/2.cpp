#include<bits/stdc++.h>
using namespace std; 
class Solution {
    vector<vector<int>> dp; 
    int f(int i,int j, vector<int>& nums){
        if(i > j) return 0; 
        if(dp[i][j] != -1) return dp[i][j]; 
        int maxi = INT_MIN; 
        for(int k = i; k<=j; k++){
            int steps = f(i, k-1, nums) + nums[i-1] * nums[k] * nums[j+1] + f(k+1, j, nums); 
            maxi = max(maxi, steps);
        }
        return dp[i][j] = maxi; 
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1); 
        int n = nums.size(); 
        dp.resize(n, vector<int>(n, -1)); 
        return f(1, n-2, nums); 
    }
};


int main(){
    vector<int> nums = {3, 1, 5, 8}; 
    Solution obj; 
    cout << "The maximum coins that can be obtained are : " << obj.maxCoins(nums); 
    return 0; 
}


