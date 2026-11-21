#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & nums)
{
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int ans = INT_MAX;
    int idx = -1;
    while(s<=e)
    {
        int mid = s+(e-s)/2;
        // When the segment is sorted
        if (nums[s] < nums[e]) {
            if (nums[s] < ans) {
                ans = nums[s];
                idx = s;
            }
            break;
        }
        if(nums[s] == nums[mid] && nums[mid] == nums[e])
        {
            if (nums[s] < ans) {
                ans = nums[s];
                idx = s;
            }
            s++;
            e--;
            continue;
        }
        if(nums[s]<=nums[e])
        {
             if(nums[s] < ans)
             {
                idx = s;
                ans = nums[s];
             }
        }
        else if(nums[s]<=nums[mid])
        {
            if(nums[s]<ans)
            {
               idx = s;
               ans = nums[s];
            }
            s=mid+1;
        }
        else
        {
            if(nums[mid]<ans)
            {
                idx = mid;
                ans = nums[mid];
            }
            e=mid-1;  
        }
    }    
    return idx;                                                                                                                                                                                                                                                                                                                                                                                            
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