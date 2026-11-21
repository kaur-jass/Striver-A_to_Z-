#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int n = height.size(); 
    int ans = 0; 
    stack<int> st;
    for(int i = 0; i<n; i++)
    {
        while(!st.empty() && height[i]>height[st.top()])
        {
            int val = st.top(); 
            st.pop(); 
            if(st.empty()) break; 
            int w = i-st.top()-1; 
            int h = min(height[i], height[st.top()]) - height[val]; 
            ans += w*h; 
        }
        st.push(i);
    }
    return ans; 
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums[i];
    }
    trap(nums);
    cout << trap(nums) << " ";
    cout << "\n";
    return 0;
}