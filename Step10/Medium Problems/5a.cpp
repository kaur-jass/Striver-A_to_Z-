#include<bits/stdc++.h>
using namespace std; 
int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int,int> mpp;
    int presum = 0;
    int cnt = 0;
    mpp[0] = 1;
    for(int i = 0; i<nums.size(); i++)
    {
        presum += nums[i];
        int remove = presum-goal;
        cnt += mpp[remove];
        mpp[presum] += 1;
    }
    return cnt;
}
int main(){
    vector<int> nums = {1,0,1,0,1}; 
    int goal = 2; 
    cout << "The No of subarrays with the given sum is : " << numSubarraysWithSum(nums, goal); 
    return 0; 
}