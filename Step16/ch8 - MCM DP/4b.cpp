#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dp; 
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(); 
        dp.resize(n+1, 0); 
        for(int idx = n-1; idx >= 0; idx--){
            int maxisum = 0; 
            int len = 0, max_ele = INT_MIN; 
            for(int j = idx; j < min(idx + k, (int)arr.size()); j++){
               len++;
               max_ele = max(max_ele, arr[j]);
               int curr = max_ele * len + dp[j+1]; 
               maxisum = max(maxisum, curr); 
            }
            dp[idx] = maxisum; 
        }
        return dp[0]; 
    }
};

int main(){
    vector<int> arr = {1,15,7,9,2,5,10}; 
    int k = 3; 
    Solution obj; 
    cout << "The maximum sum after partitioning the array is : " << obj.maxSumAfterPartitioning(arr, k); 
    return 0; 
}