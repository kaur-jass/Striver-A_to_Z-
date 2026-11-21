#include<bits/stdc++.h>
using namespace std; 
int fruitsintobasket(vector<int>& nums) {
    int n = nums.size(); 
    int maxlen = 0; 
    int l = 0;
    int zeroes = 0; 
    int r = 0;
    unordered_map<int, int> mpp;  
    while(r<n){
        mpp[nums[r]]++; 
        if(mpp.size()>2){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            } 
            l++; 
        }
        if(mpp.size() <= 2){
            maxlen = max(maxlen, r-l+1); 
        }
        r++;
    }
    return maxlen; 
}
int main(){
    vector<int> nums = {1,2,1,3,3,3,1,2}; 
    cout << "Ans is : " << fruitsintobasket(nums); 
    return 0; 
}