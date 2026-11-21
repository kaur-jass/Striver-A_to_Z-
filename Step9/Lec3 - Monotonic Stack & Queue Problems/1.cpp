#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(); 
    int n2 = nums2.size(); 
    vector<int> ans; 
    for(int i = 0; i < n1; i++)
    {
        int a = nums1[i]; 
        int idx = 0;
        int mini = -1;  
        for(int i = 0; i<n2; i++)
        {
            if(nums2[i] == a)
            {
                idx = i; 
                break; 
            }
        }
        for(int i = idx; i<n2; i++)
        {
            if(nums2[i] > a)
            {
                mini = nums2[i]; 
                break; 
            }
        }
        ans.push_back(mini); 
    } 
    return ans; 
}


int main()
{
    int n1, n2; 
    cin >> n1 >> n2; 
    vector<int> nums1(n1); 
    vector<int> nums2(n2); 
    for(int i = 0; i<n1; i++) cin >> nums1[i]; 
    for(int i = 0; i<n2; i++) cin >> nums2[i]; 
    vector<int> ans = nextGreaterElement(nums1, nums2); 
    for(auto x : ans) cout << x << " "; 
    cout << "\n"; 
    return 0; 
}