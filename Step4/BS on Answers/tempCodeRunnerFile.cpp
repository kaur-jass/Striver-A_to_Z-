#include<bits/stdc++.h>
using namespace std;

double findkthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) 
{
    int i = 0; 
    int j = 0; 
    int ans = 0; 
    while(k--)
    {
       if(nums1[i] < nums2[j])
       {
           ans = nums1[i];
           i++;
       }
       else
       { 
           ans = nums2[j];
           j++;
       }
    }
    return ans;
}

int main()
{
    int m; 
    cin >> m; 
    vector<int> arr1(m);
    for(int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    int n;
    cin >> n;
    vector<int> arr2(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int k; 
    cin >> k;
    cout << findkthSortedArrays(arr1, arr2,k) << endl;
    
}