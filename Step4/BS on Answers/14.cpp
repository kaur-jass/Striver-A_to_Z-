#include<bits/stdc++.h>
using namespace std;

double findkthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) 
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector <int> merged;
    int i = 0, j = 0;
    while(i < n1 && j <n2)
    {
        if(nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
        else merged.push_back(nums2[j++]);
    }
    while(i < n1)
    {
        merged.push_back(nums1[i++]);
    }
    while(j < n2)
    {
        merged.push_back(nums2[j++]);
    }
    return merged[k-1]; 
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