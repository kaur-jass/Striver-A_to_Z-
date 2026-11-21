#include<bits/stdc++.h>
using namespace std;
// Taking too much time complexity so thats why this one is a brute forec soln 
int count_inversions(vector<int>& k,vector<vector<int>>& requirements)
{
    for(auto r : requirements)
    {
        int end = r[0];
        int cnt = r[1];
        int inv = 0; 
        for(int i = 0; i <= end; i++)
        {
            for(int j = i+1 ; j <= end; j++)
            {
                if(k[i] > k[j]) inv++;
            }
        }
        if(inv != cnt) return 0;
    }
     return 1;
}
int numberOfPermutations(int n, vector<vector<int>>& requirements)
{
    vector<int> nums(n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        nums[i] = i;
    }
    map<int,vector<int>> mpp;
    int idx = 0;
    do
    {
        mpp[idx] = nums;
        idx++;
    }while(next_permutation(nums.begin(),nums.end()));
    int i = 0;
    int ans = 0; 
    while(i < mpp.size())
    {
        vector<int> k = mpp[i]; 
        ans += count_inversions(k,requirements);
        i++;
    }
    return ans;
}


// int numberOfPermutations(int n, vector<vector<int>>& requirements)
// {
//     vector<int> nums(n);
//     int ans = 0;
//     for(int i = 0; i < n; i++)
//     {
//         nums[i] = i;
//     }
//     do
//     {
//         if (count_inversions(nums, requirements)) {
//         ans++;
//         }
//     }while(next_permutation(nums.begin(),nums.end()));
//     return ans;
// }
int main()
{
    int m; 
    cin >> m;
    vector<vector<int>> v(m, vector<int>(2, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    int n; 
    cin >> n;
    cout << numberOfPermutations(n,v) << " ";
    return 0;
}