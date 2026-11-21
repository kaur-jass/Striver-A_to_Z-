#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dp; 
    int max_sum(int idx, vector<int>& arr, int k){
        if(idx == arr.size()) return 0; 
        if (dp[idx] != -1) return dp[idx];
        int maxisum = 0; 
        int len = 0, max_ele = INT_MIN; 
        for(int j = idx; j < min(idx + k, (int)arr.size()); j++){
           len++;
           max_ele = max(max_ele, arr[j]);
           int curr = max_ele * len + max_sum(j+1, arr, k); 
           maxisum = max(maxisum, curr); 
        }
        return dp[idx] = maxisum; 
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