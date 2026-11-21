#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int s= 0;
    int e = n-1;
    int ans=n;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(nums[mid] >= target)
        {
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid] < target)
        {
            s = mid+1;
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
    int target;
    cin >> target;
    cout << search(nums, target) << endl;
    return 0;
}