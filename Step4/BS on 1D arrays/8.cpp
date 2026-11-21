#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & nums, int target)
{
    int n = nums.size();
    int s = 0, e = n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(nums[mid] == target)
        {
            return mid;
        }  
        // Left half is sorted
        if (nums[s] <= nums[mid]) {
            if (nums[s] <= target && target < nums[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[e])
                s = mid + 1;
            else
                e = mid - 1;
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
    int k;
    cin >> k;
    cout << search(nums, k) << endl;
    return 0;
}