#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int func(vector<int>& nums, int ind, int jumps){
        if(ind >= nums.size()-1) return jumps; 
        int ans = INT_MAX; 
        for(int i = 1; i<=nums[ind]; i++){
            ans = min(ans, func(nums, ind+i, jumps+1));
        }
        return ans; 
    }
    int jump(vector<int>& nums) {
        int ans = func(nums, 0, 0);
        return ans; 
    }
};
int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    Solution s;
    cout<<s.jump(nums);
}