#include<bits/stdc++.h>
using namespace std;
vector<int> sum(vector<int>& nums)
{
    int n = nums.size();
    int maxi =  INT_MIN;
    int sum = 0;
    int ans_start = 0;
    int tempstart = 0;
    int ans_end = -1;
    for(int i = 0; i<n; i++)
    {
        sum = sum + nums[i];
        if(sum>maxi)
        {
            maxi = sum;
            ans_start = tempstart;
            ans_end = i;
        }
        if(sum < 0)
        {
            sum = 0;
            tempstart = i+1;
        }
    }
    vector<int> ans;
    for(int i = ans_start; i<=ans_end ; i++)
    {
        ans.push_back(nums[i]);
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
    vector<int> ans = sum(nums);
    for (int i = 0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}