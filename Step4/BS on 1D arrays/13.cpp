#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int s = 1; 
    int e = n-2;
    if (n == 1) return nums[0];
    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n-1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid] > nums[mid-1]) s= mid+1;
        else  e = mid-1;
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
    cout << findPeakElement(nums) << endl;
    return 0;
}