#include<bits/stdc++.h>
using namespace std;
int sum(vector<int>& nums)
{
    int n = nums.size();
    int maxi = 0;
    for(int i = 0; i<n; i++)
    {
        int sum = 0;
        for(int j = i; j<n; j++)
        {
            sum += nums[j];
            maxi = max(sum,maxi);
        }
    }
    return maxi;
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
    cout << "The maximum length of the subarray is " << sum(nums) << endl;
    return 0;
}