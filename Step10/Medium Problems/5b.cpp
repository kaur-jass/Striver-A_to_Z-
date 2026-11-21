#include<bits/stdc++.h>
using namespace std; 
int Subarray(vector<int>& nums, int goal){
    if(goal<0) return 0; 
    int n = nums.size(); 
    long long cnt = 0; 
    int l = 0; 
    int r = 0; 
    long long sum = 0; 
    while(r<n){
        sum += nums[r]; 
        while(sum > goal){
            sum -= nums[l]; 
            l++; 
        }
        cnt += r-l+1; 
        r++; 
    }
    return cnt; 
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return Subarray(nums, goal)-Subarray(nums, goal-1);
}
int main(){
    vector<int> nums = {1,0,1,0,1}; 
    int goal = 2; 
    cout << "The No of subarrays with the given sum is : " << numSubarraysWithSum(nums, goal); 
    return 0; 
}
