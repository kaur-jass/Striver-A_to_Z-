#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind = 0; 
        for(int i = 0; i<nums.size(); i++){
            if(i>maxind) return false;
            maxind = max(maxind,i+nums[i]);   
        }
        return true; 
    }
};
int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    Solution s;
    cout<<s.canJump(nums);
}