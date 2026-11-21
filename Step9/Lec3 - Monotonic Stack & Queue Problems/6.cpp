#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size(); 
    long long sum = 0;
    const int MOD = 1e9 + 7;
    for(int i = 0; i<n; i++)
    { 
        int mini = arr[i];  
        for(int j = i; j<n; j++)
        {
            mini = min(mini, arr[j]);; 
            sum = (sum+mini) % MOD; 
        }
    }
    return sum; 
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums[i];
    }
    sumSubarrayMins(nums);
    cout << sumSubarrayMins(nums) << " ";
    cout << "\n";
    return 0;
}