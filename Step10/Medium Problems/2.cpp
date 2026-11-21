#include<bits/stdc++.h>
using namespace std; 
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size(); 
    int maxlen = 0; 
    for(int i = 0; i<n; i++){
        int len = n-i;
        int zeroes = 0; 
        for(int j = i; j<n; j++){
            if(nums[j] == 0) zeroes++; 
            if(zeroes > k){
                len = j-i;
                break;  
            }
        } 
        maxlen = max(len,maxlen);
    } 
    return maxlen; 
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0}; 
    int k = 2; 
    cout << "The length of the Longest Ones are : " << longestOnes(nums, k); 
    return 0; 
}