#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int>& nums1) {
    int n1 = nums1.size();
    vector<int> ans; 
    for(int i = 0; i < n1; i++)
    {
        
        int mini = -1;
        int a = nums1[i];
        for(int j = i; j<n1; j++)
        {
            if(nums1[j] < a)
            {
                mini = nums1[j]; 
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
    cin >> n1; 
    vector<int> nums1(n1);
    for(int i = 0; i<n1; i++) cin >> nums1[i];
    vector<int> ans = nextSmallerElement(nums1); 
    for(auto x : ans) cout << x << " "; 
    cout << "\n"; 
    return 0; 
}