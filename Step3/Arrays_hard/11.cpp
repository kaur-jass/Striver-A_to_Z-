#include<bits/stdc++.h>
using namespace std;
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            long long ans = 2LL *nums[j];
            if(nums[i]>ans) cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n; 
    cin >> n; 
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << reversePairs(nums) << endl;
    return 0;
}