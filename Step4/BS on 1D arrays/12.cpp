#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & nums)
{
    int n = nums.size();
    if (n==1) return nums[0];
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            if(nums[0] != nums[1]) return nums[0];
        }
        else if(i == n-1)
        {
            if(nums[n-1] != nums[n-1]) return nums[n-1];
        }
        else
        {
            if (nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i]; 
        }
    }
    return -1;
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
    cout << search(nums) << endl;
    return 0;
}