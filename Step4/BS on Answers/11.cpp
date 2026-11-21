#include<bits/stdc++.h>
using namespace std;
// Same problem painters partioning 
int largest(vector<int>& nums)
{
    int n= nums.size();
    int maxx = INT_MIN; 
    for(int i = 0; i<n;i++)
    {
        if(nums[i] > maxx)
        {
            maxx = nums[i];
        }
    }
    return maxx;
}

int largest_sum(vector<int> &nums, int m, int k)
{
    int n = nums.size();
    int largestsum = 1; 
    int total = 0; 
    for(int i = 0; i<n; i++)
    {
        if(nums[i] > m) return k+1; // if any of the subarray element sum is greater than  m so thers is not any subarray which can be formed by this element so return k+1 which  is greater than k
        if(total+nums[i] > m)
        {
            largestsum++;
            total = nums[i];   // start new subarray with current element
        }
        else total += nums[i];
    }
    return largestsum;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int s = largest(nums);
    int sum = 0;
    for(int i = 0; i<n; i++)  sum += nums[i];
    int e = sum; 
    int ans = 0;
    while(s<=e)
    {
        int m = s+(e-s)/2;
        int largest = largest_sum(nums,m,k);
        if(largest<=k)
        {
            ans = m; 
            e = m-1;
        }
        else 
        {
            s = m+1;
        }
    }
return ans; 
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
    int k; 
    cin >> k;
    int pages = splitArray(nums, k);
    cout << pages << endl;
    return 0;
}