                         #include<bits/stdc++.h>
using namespace std;
// 1st Optimal Solution......

int first_index(vector<int> &nums,int n,int target)
{
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid]==target)
        {
            first = mid;
            high = mid-1;
        }
        else if(nums[mid]<= target)
        {
             low = mid+1;
        }
        else 
        {
            high = mid-1;
        }
    }
    return first;
}

int last_index(vector<int> &nums,int n,int target)
{
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid]==target)
        {
            last = mid;
            low = mid+1;
        }
        else if(nums[mid]<= target)
        {
             low = mid+1;
        }
        else 
        {
            high = mid-1;
        }
    }
    return last;
}
int searchRange(vector<int>& nums, int target) {
     int n = nums.size();
     int first = first_index(nums,n,target);
     if (first == -1) return -1;
     int last = last_index(nums,n,target);
     return (last-first+1);
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
    cout << searchRange(a,k);
    return 0;

}
