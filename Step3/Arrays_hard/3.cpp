#include<bits/stdc++.h>
using namespace std;

// using set data structure... Will store only unique elements..... 

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> temp;
//         for(int i = 0; i<n; i++)
//         {
//             for(int j = i+1; j<n; j++)
//             {
//                 for(int k = j+1; k<n; k++)
//                 {
//                     vector<int> ls;
//                     if(nums[i]+nums[j]+nums[k] == 0)
//                     {
//                             ls = {nums[i], nums[j], nums[k]};
//                             sort(ls.begin(), ls.end());
//                             temp.insert(ls);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(temp.begin(),temp.end());
//         return ans;  
//     }
// };
vector<vector<int>> three_sum(const vector<int> &nums)
{ 
    int n = nums.size();
    vector<vector<int>> temp;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            for(int k = j+1; k<n; k++)
            {
                vector<int>ls;
                if(nums[i]+nums[j]+nums[k] == 0)
                {
                    ls = {nums[i], nums[j], nums[k]};
                    sort(ls.begin(), ls.end());
                    if(find(temp.begin(), temp.end(),ls) == temp.end())
                    temp.push_back(ls);
                }       
            }
        }
    }
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
    vector<vector<int>> arr = three_sum(nums);
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
                cout << arr[i][j] << " ";
        }
    }
    return 0;
}
