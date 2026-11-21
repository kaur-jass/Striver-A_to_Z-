#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & nums)
{
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int ans = INT_MAX;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(nums[s] == nums[mid] && nums[mid] == nums[e])
        {
            s++;
            e--;
        }
        if(nums[s]<nums[e]) return nums[s];
        else if(nums[s]<=nums[mid])
        {
            ans = min(ans,nums[s]);
            s=mid+1;
        }
        else
        {
            ans = min(ans,nums[mid]);
            e=mid-1;  
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
    cout << search(nums) << endl;
    return 0;
}