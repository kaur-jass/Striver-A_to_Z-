#include<bits/stdc++.h>
using namespace std; 

class Solution {
private:
    vector<int> dp; 
    int house(int start, int idx,  vector<int>& nums){
        if (idx < start) return 0;
        if(idx == start) return nums[idx];
        if(dp[idx] != -1) return dp[idx]; 
        int pick = nums[idx]; 
        if(idx>1) pick += house(start, idx-2, nums); 
        int nonpick = house(start, idx-1, nums);
        return dp[idx]  = max(pick, nonpick);         
    }
public:
    int rob(vector<int>& nums) {
        // using memoization 
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