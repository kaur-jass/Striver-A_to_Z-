#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dp; 
    int max_sum(int idx, vector<int>& arr, int k){
        if(idx == arr.size()) return 0; 
        if (dp[idx] != -1) return dp[idx];
        int sum = 0; 
        int max_ele = 0; 
        for(int len = 1; len <= k && idx + len <= arr.size(); len++){
           max_ele = *max_element(arr.begin() + idx, arr.begin()+idx+len); 
           int curr = max_ele * len + max_sum(idx+len, arr, k); 
           sum = max(sum, curr); 
        }
        return dp[idx] = sum; 
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(); 
        dp.resize(n, -1); 
        return max_sum(0, arr, k); 
    }
};

int main(){
    vector<int> arr = {1,15,7,9,2,5,10}; 
    int k = 3; 
    Solution obj; 
    cout << "The maximum sum after partitioning the array is : " << obj.maxSumAfterPartitioning(arr, k); 
    return 0; 
}