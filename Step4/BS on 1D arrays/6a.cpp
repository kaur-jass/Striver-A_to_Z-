#include<bits/stdc++.h>
using namespace std;
// 1st Optimal Solution......

int lower_bound(vector<int> &nums,int n,int target)
{
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

int upper_bound(vector<int> &nums,int n,int target)
{
    int s= 0;
    int e = n-1;
    int ans=n;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(nums[mid] > target)
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
vector<int> searchRange(vector<int>& nums, int target) {
     int n = nums.size();
     int lb = lower_bound(nums,n,target);
     if (lb == n || nums[lb] != target) return {-1,-1};
     return{lb,upper_bound(nums,n,target)-1};
}
int main()
{
    int n;
    cin >> n;
 vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> temp = searchRange(a,k);
    for(int i = 0; i<temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    return 0;

}
