#include<bits/stdc++.h>
using namespace std;
int sum(vector<int>& nums)
{
    int n = nums.size();
    int maxi =  INT_MIN;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum = sum + nums[i];
        if(sum>maxi)
        {
            maxi = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    // if (sum < 0) maxi = 0;
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
    cout << "The maximum sum of the subarray is " << sum(nums) << endl;
    return 0;
}