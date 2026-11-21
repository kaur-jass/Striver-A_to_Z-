#include<bits/stdc++.h>
using namespace std; 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
     int left = 0;
     int right = 0;
     vector<int> result;
     while(left < m && right < n) 
     {
        if(nums1[left] < nums2[right]) 
        {
            result.push_back(nums1[left]);
            left++;
        }
        else 
        {
            result.push_back(nums2[right]);
            right++;
        }
     }
     while(left<m)
     {
         result.push_back(nums1[left]);
         left++;
     }
     while(right<n)
     {
        result.push_back(nums2[right]);
        right++;
     }

     for(int i = 0; i < result.size(); i++)
     {
        if(i<m) nums1[i] = result[i];
        else nums2[i] = result[i-m];
     }

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
