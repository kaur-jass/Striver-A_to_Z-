#include<bits/stdc++.h>
using namespace std; 
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size(); 
    int maxlen = 0; 
    int l = 0;
    int zeroes = 0; 
    int r = 0; 
    while(r<n){
        if(nums[r]==0) zeroes++; 
        if(zeroes>k){
            if(nums[l] == 0) zeroes--; 
            l++; 
        }
        if(zeroes <= k){
            maxlen = max(maxlen, r-l+1); 
        }
        r++;
    }
    return maxlen; 
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0}; 
    int k = 2; 
    cout << "The length of the Longest Ones are : " << longestOnes(nums, k); 
    return 0; 
}