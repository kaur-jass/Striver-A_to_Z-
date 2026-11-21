#include<bits/stdc++.h>
using namespace std; 
class Solution {
    vector<vector<int>> dp; 
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1); 
        int n = nums.size(); 
        dp.resize(n+2, vector<int>(n+2, 0)); 
        for(int i = n-2; i>=1; i--){
            for(int j = i; j<=n-2; j++){
                if(i > j) continue;
                int maxi = INT_MIN; 
                for(int k = i; k<=j; k++){
                    int steps = dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j]; 
                    maxi = max(maxi, steps);
                }
                dp[i][j] = maxi; 
            }
        }
        return dp[1][n-2]; 
    }
};


int main(){
    vector<int> nums = {3, 1, 5, 8}; 
    Solution obj; 
    cout << "The maximum coins that can be obtained are : " << obj.maxCoins(nums); 
    return 0; 
}


