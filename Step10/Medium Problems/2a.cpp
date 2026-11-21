#include<bits/stdc++.h>
using namespace std; 
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size(); 
    int maxlen = 0; 
    int l = 0;
    int zeroes = 0; 
    for(int r = 0; r<n; r++){
        if(nums[r]==0) zeroes++; 
        while(zeroes>k){
            if(nums[l] == 0) zeroes--; 
            l++; 
        }
        maxlen = max(maxlen, r-l+1); 
    }
    return maxlen; 
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0}; 
    int k = 2; 
    cout << "The length of the Longest Ones are : " << longestOnes(nums, k); 
    return 0; 
}