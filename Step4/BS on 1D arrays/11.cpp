#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & nums)
{
    int n = nums.size();
    int cnt = 0;
    while(!is_sorted(nums.begin(),nums.end()))
    {
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+1);
       reverse(nums.begin()+1,nums.end());
       cnt++;
    }
    return cnt;
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
    cout << search(nums) << endl;
    return 0;
}