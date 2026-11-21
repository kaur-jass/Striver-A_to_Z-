#include<bits/stdc++.h>
using namespace std; 
long long Subarray(vector<int>& nums, int k){
    if(k<0) return 0;
    int n = nums.size();  
    int l = 0; 
    int r = 0; 
    long long cnt = 0; 
    long long sum = 0; 
    while(r<n){
        sum += (nums[r]%2); 
        while(sum>k){
            sum -= (nums[l]%2); 
            l++;
        }
        cnt += r-l+1; 
        r++; 
    }
    return cnt; 
}
int numberOfSubarrays(vector<int>& nums, int k){
    return Subarray(nums,k)-Subarray(nums,k-1); 
}
int main(){
    vector<int> nums = {1,1,2,1,1}; 
    int goal = 3; 
    cout << "The No of subarrays with the k odd nos is : " << numberOfSubarrays(nums, goal); 
    return 0;
}