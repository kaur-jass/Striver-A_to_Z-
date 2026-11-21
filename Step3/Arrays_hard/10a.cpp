#include<bits/stdc++.h>
using namespace std;
// // Taking too much time complexity so thats why this one is a brute forec soln 
int merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low; 
    int cnt  = 0;
    int right = mid+1;
    while(left <= mid && right <= high)
    {
        if(nums[left] < nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else 
        {
            temp.push_back(nums[right]);
            cnt += (mid-left+1);
            right++;
        }
    }
    while(left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low; i <= high; i++)
    {
        nums[i] = temp[i-low];
    }
    return cnt;
}
int merge_sort(vector<int> &nums, int low,int high)
{
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low+high)/2;
    cnt += merge_sort(nums, low, mid);
    cnt += merge_sort(nums, mid+1, high);  
    cnt += merge(nums, low, mid, high);
    return cnt;
}
int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << merge_sort(v, 0, n-1) << " ";
    return 0;
}