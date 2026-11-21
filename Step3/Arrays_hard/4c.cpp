#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n  = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n; j++)
        {
            if(j != i+1 && nums[j] == nums[j-1]) continue; // Avoid duplicates 
            int k = j+1;
            int l = n-1;
            while(k<l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum < target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    res.push_back(temp);
                    k++,l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return res;
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
    int target;
    cin >> target;
    vector<vector<int>> arr = fourSum(nums,target);
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
                cout << arr[i][j] << " ";
        }
    }
    return 0;
}