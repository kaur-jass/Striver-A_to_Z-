#include<bits/stdc++.h>
using namespace std; 

class Solution {
private:
    vector<int> dp; 
    int house(int start, int end,  vector<int>& nums){
        dp[start] = nums[start]; 
        if(start == end) return dp[start]; 
        dp[start+1] = max(nums[start], nums[start+1]); 
        for(int i = start+2; i<=end; i++){
            int pick = nums[i]; 
            if(i>1) pick += dp[i-2]; 
            int nonpick = 0 + dp[i-1]; 
            dp[i] = max(pick, nonpick); 
        }
        return dp[end]; 
    }
public:
    int rob(vector<int>& nums) {
        // using tabulization 
        int n = nums.size();
        if(n==1) return nums[0]; 
        dp.assign(n, -1);
        int ans1 = house(1, n - 1, nums);
        dp.assign(n, -1);
        int ans2 = house(0, n - 2, nums);
        return max(ans1, ans2); 
    }
};

int main(){
    int n; 
    cout << "Enter the no. of houses: "; 
    cin >> n; 
    cout << "Enter the money in the respective house: "; 
    Solution obj; 
    vector<int> house(n); 
    for(int i = 0; i<n; i++) cin >> house[i]; 
    cout << "The maximum money a robber can rob from houses: " << obj.rob(house) << endl; 
    return 0;
}