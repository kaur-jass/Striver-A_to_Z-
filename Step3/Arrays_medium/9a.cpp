#include<bits/stdc++.h>
using namespace std;


vector<int> leaders(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans;
    int max = nums[n-1];
    ans.push_back(max);
    for(int i = n-1; i >= 0; i--)
    {
        if (nums[i] > max)
        {
            ans.push_back(nums[i]);
            max = nums[i];
        }
    }
    int left = 0;
    int right = ans.size() - 1;
    while(left <right)
    {
        swap(ans[left], ans[right]);
        left++;
        right--;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> ans = leaders (nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}