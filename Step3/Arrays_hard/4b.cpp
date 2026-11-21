#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target) 
{
   int n= nums.size();
   set<vector<int>> st;
   for(int i = 0; i<n; i++)
   {
       for(int j = i+1; j<n; j++)
       {
           set<long long> hashset; 
           for(int k = j+1; k<n; k++)
           {
               long long sum = nums[i] + nums[j];
               sum += nums[k]; 
               long long fourth = target - sum;
               if(hashset.find(fourth)!=hashset.end())
               {
                   vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                   sort(temp.begin(), temp.end());
               }
               hashset.insert(nums[k]);
           }
       }
   }
   vector<vector<int>> ans(st.begin(),st.end());
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