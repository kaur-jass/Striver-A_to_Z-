#include<bits/stdc++.h>
using namespace std; 
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size(); 
    int ans = 0; 
    for(int i = 0; i<n; i++){
        int cnt = 0; 
        for(int j = i; j<n; j++){
            if(nums[j] & 1) cnt++; 
            if(cnt == k) ans++; 
            if(cnt>k) break; 
        }
    }
    return ans; 
}
int main(){
    vector<int> nums = {1,1,2,1,1}; 
    int goal = 3; 
    cout << "The No of subarrays with the k odd nos is : " << numberOfSubarrays(nums, goal); 
    return 0;
}