#include<bits/stdc++.h>
using namespace std; 
int subarray(vector<int>& nums, int k){
    int n = nums.size(); 
    unordered_map<int, int> mpp; 
    int l = 0; 
    int r = 0; 
    int cnt = 0; 
    while(r<n){
        mpp[nums[r]]++; 
        while(mpp.size() > k){
            mpp[nums[l]]--; 
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]); 
            l++; 
        }
        cnt += r-l+1; 
        r++; 
    }
    return cnt; 
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return (subarray(nums, k) - subarray(nums, k-1));  
}
int main(){
    vector<int> nums = {1,2,1,2,3}; 
    int k = 2; 
    cout << "The no of subarray with exactly k distinct elements are : " << subarraysWithKDistinct(nums, k); 
    return 0; 
}