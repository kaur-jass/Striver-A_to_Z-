#include<bits/stdc++.h>
using namespace std;


vector<int> leaders(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i <n; i++)
    {
        bool isLeader = true;
        for(int j = i+1; j < n; j++)
        {
            if(nums[j] > nums[i])
            {
                isLeader = false;
                break;
            }
        }
        if(isLeader)
        {
            ans.push_back(nums[i]);
        }
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
    int k; 
    cin >> k;
    vector<int> ans = leaders (nums, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}