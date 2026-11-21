#include<bits/stdc++.h>
using namespace std;

int nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(); 
    int n2 = nums2.size(); 
    vector<int> ans; 
    stack<int> st; 
    unordered_map<int,int> mp;  // maps each num in nums2 to its NGE
    for(int i = n2-1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= nums2[i])
        {
            st.pop(); 
        }
        mp[nums2[i]] = st.empty() ? -1 : st.top(); 
        st.push(nums2[i]);  
    } 
    for (int x : nums1) {
        ans.push_back(mp[x]);
    }
    int anss= 0;
    for(auto x: ans)
    {
        if(x != -1)
        {
            anss++;
        }
    }
    return anss;
}
int main()
{
    int n1, n2; 
    cin >> n1 >> n2; 
    vector<int> nums1(n1); 
    vector<int> nums2(n2); 
    for(int i = 0; i<n1; i++) cin >> nums1[i]; 
    for(int i = 0; i<n2; i++) cin >> nums2[i]; 
    int ansss = nextGreaterElement(nums1, nums2); 
    cout << ansss << " "; 
    cout << "\n"; 
    return 0; 
}