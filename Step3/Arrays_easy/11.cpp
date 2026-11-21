#include<bits/stdc++.h>
using namespace std;
int max_one(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 1) 
        {
            cnt++;
        }
        else 
        {
            ans.push_back(cnt);
            cnt = 0;
        }
    }
    ans.push_back(cnt); // To account for the last segment of 1's if it ends at the last element
    if(ans.size() == 0) return 0; // If there are no
    int max = ans[0];
    for(int i = 1; i < ans.size(); i++)
    {
        if(ans[i] > max) max = ans[i];
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = max_one(nums);
    cout << "Maximum number of consecutive 1's: " << result << endl;
    return 0;
}