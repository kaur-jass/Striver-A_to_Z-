#include<bits/stdc++.h>
using namespace std;

int floor(vector<int>& nums, int target) {
    int n = nums.size();
    int s= 0;
    int e = n-1;
    int ans= -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(nums[mid] <= target)
        {
            ans = nums[mid];
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}
int ceil(vector<int>& nums, int target) {
    int n = nums.size();
    int s= 0;
    int e = n-1;
    int ceil=n;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(nums[mid] >= target)
        {
            ceil = mid;
            e = mid-1;
        }
        else if(nums[mid] < target)
        {
            s = mid+1;
        }
    }
    return nums[ceil];
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
    cout << floor(nums, target) << " " << ceil(nums, target) << endl;
    return 0;
}