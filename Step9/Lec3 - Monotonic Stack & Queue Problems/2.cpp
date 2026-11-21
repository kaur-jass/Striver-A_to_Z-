#include<bits/stdc++.h>
using namespace std;

 vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> ans(n,-1); 
        stack<int> st;  
        for(int i = 2*n-1; i>=0; i--){
            int idx = i%n; 
            while(!st.empty() && st.top() <=nums[idx]) st.pop(); 
            if(i<n)
            {
                ans[idx] = st.empty() ? -1 : st.top(); 
            }
            st.push(nums[idx]);
        }
        return ans; 
    }
int main()
{
    int n;  
    cin >> n; 
    vector<int> nums1(n); 
    for(int i = 0; i<n; i++) cin >> nums1[i]; 
    vector<int> ans = nextGreaterElements(nums1); 
    for(auto x : ans) cout << x << " "; 
    cout << "\n"; 
    return 0; 
}