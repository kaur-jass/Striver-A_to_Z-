#include<bits/stdc++.h>
using namespace std; 
class Solution{
    private:
        vector<int> dp; 
        int houses(int idx, vector<int>& nums){
            if(idx == 0) return nums[idx]; 
            if(idx<0) return 0; 
            if(dp[idx] != -1) return dp[idx]; 
            int pick = nums[idx]; 
            if(idx>1) pick += houses(idx-2, nums); 
            int nonpick = 0 + houses(idx-1, nums); 
            return dp[idx] = max(pick, nonpick); 
        }
    public:
        int rob(vector<int>& nums){
            int n = nums.size(); 
            if(n == 1) return nums[0]; 
            dp.resize(n+1, -1); 
            return houses(n-1, nums); 
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