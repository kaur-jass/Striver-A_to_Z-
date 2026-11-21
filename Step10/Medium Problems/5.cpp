#include<bits/stdc++.h>
using namespace std; 
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size(); 
    int cnt = 0; 
    for(int i = 0; i<n; i++){
        int sum = 0; 
        for(int j = i; j<n; j++){
            sum += nums[j]; 
            if(sum == goal) cnt++; 
        }
    }
    return cnt; 
}
int main(){
    vector<int> nums = {1,0,1,0,1}; 
    int goal = 2; 
    cout << "The No of subarrays with the given sum is : " << numSubarraysWithSum(nums, goal); 
    return 0; 
}