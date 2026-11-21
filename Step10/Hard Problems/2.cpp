#include<bits/stdc++.h>
using namespace std; 
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size(); 
    int cnt = 0; 
    for(int i = 0; i<n; i++){
        unordered_map<int, int> mpp; 
        for(int j = i; j<n; j++){
            mpp[nums[j]]++; 
            if(mpp.size() == k) cnt++; 
        }
    } 
    return cnt; 
}
int main(){
    vector<int> nums = {1,2,1,2,3}; 
    int k = 2; 
    cout << "The no of subarray with exactly k distinct elements are : " << subarraysWithKDistinct(nums, k); 
    return 0; 
}