#include<bits/stdc++.h>
using namespace std; 

class Solution{
    vector<vector<int>> dp; 
    int f(vector<int> &arr){
        for(int i = arr.size()-1; i >= 1; i--){
            for(int j = i+1; j<arr.size(); j++){
                int mini = 1e9; 
                for(int k = i; k<j; k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]; 
                    if(steps<mini) mini = steps; 
                }
                dp[i][j] = mini; 
            }   
        }
        return dp[1][arr.size()-1]; 
    }

    public: 
    int MMultiply(vector<int> &arr, int n){
        dp.resize(n, vector<int>(n, 0)); 
        return f(arr); 
    }
};

int main(){
    vector<int> arr = {10, 20 , 30, 40, 50}; 
    Solution obj; 
    cout << "The minimum operations needed to multiply the arrays are : " << obj.MMultiply(arr, arr.size()); 
    return 0; 
}