#include<bits/stdc++.h>
using namespace std; 
class Solution{
    private:
        vector<int> dp; 
        int houses(vector<int>& nums){
            dp[0] = nums[0]; 
            for(int i = 1; i<nums.size(); i++){
                int pick = nums[i]; 
                if(i>1) pick += dp[i-2];
                int nonpick = 0 + dp[i-1]; 
                dp[i] = max(pick, nonpick); 
            }
            return dp[nums.size()-1]; 
        }
    public:
        int rob(vector<int>& nums){
            int n = nums.size(); 
            if(n == 1) return nums[0]; 
            dp.resize(n+1, -1); 
            return houses(nums); 
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