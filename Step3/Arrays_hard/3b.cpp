#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> triple(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0; i<n; i++)
    {
        set<int> hashset;
        for(int j = i+1; j<n; j++)
        {
            int third = -(nums[i]+nums[j]);
            if(hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
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
    vector<vector<int>> arr = triple(nums);
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
                cout << arr[i][j] << " ";
        }
    }
    return 0;
}