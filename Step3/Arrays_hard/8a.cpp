#include<bits/stdc++.h>
using namespace std; 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int r = 0;
    // for(int i = n-1; i>=0; i--)
    // {
    //     if(nums1[i] != 0)
    //     {
    //         l = i+1; 
    //         break;
    //     }
    // }
    int l = m;
    while(r<n)
    {
        nums1[l] = nums2[r];
        l++;
        r++;
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{
    int m; 
    cin >> m;
    int n; 
    cin >> n;
    vector<int> nums1(m+n);  // Here m+n is the total size() nums1+nums2;  [1,2,4,0,0,0] so m+n here is 6
    for(int i = 0; i<m+n; i++)
    {
        cin >> nums1[i];
    }
    vector<int> nums2(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums2[i];
    }
    merge(nums1, m, nums2, n);
    for(int i = 0; i<m+n; i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}