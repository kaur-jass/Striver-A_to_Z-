#include<bits/stdc++.h>
using namespace std; 

class Solution {
private:
    int house(int start, int end, vector<int>& nums) {
        int prev2 = 0;
        int prev = 0;

        for(int i = start; i <= end; i++) {
            int pick = nums[i] + prev2;
            int nonPick = prev;
            int curr = max(pick, nonPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        // using space optimisation 
        int n = nums.size();
        if(n==1) return nums[0]; 
        int ans1 = house(1, n - 1, nums);
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