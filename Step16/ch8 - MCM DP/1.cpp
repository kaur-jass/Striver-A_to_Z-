#include<bits/stdc++.h>
using namespace std; 

class Solution{
    vector<vector<int>> dp; 
    int f(int i, int j, vector<int> &arr){
        if(i==j) return 0; 
        if(dp[i][j] != -1) return dp[i][j]; 
        int mini = 1e9; 
        for(int k = i; k<j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr) + f(k+1, j, arr); 
            if(steps<mini) mini = steps; 
        }
        return dp[i][j] = mini; 
    }

    public: 
    int MMultiply(vector<int> &arr, int n){
        dp.resize(n, vector<int>(n, -1)); 
        return f(1, n-1, arr); 
    }
};

int main(){
    vector<int> arr = {10, 20 , 30, 40, 50}; 
    Solution obj; 
    cout << "The minimum operations needed to multiply the arrays are : " << obj.MMultiply(arr, arr.size()); 
    return 0; 
}