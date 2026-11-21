#include<bits/stdc++.h>
using namespace std; 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    
}

int main()
{
    int m; 
    cin >> m;
    int n; 
    cin >> n;
    vector<int> nums1(m);  
    for(int i = 0; i<m; i++)
    {
        cin >> nums1[i];
    }
    vector<int> nums2(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums2[i];
    }
    merge(nums1, m, nums2, n);
    for(int i = 0; i<m; i++)
    {
        cout << nums1[i] << " ";
    }
    for(int i = 0; i<n; i++)
    {
        cout << nums2[i] << " ";
    }
    return 0;
}
