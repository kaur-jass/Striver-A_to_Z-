#include<bits/stdc++.h>
using namespace std;

int search(vector<int> & nums)
{
    int n = nums.size();
    if(n == 1) return nums[0];
    int s = 0, e = 1;
    int ans = -1;
    while(s<e && e<n)
    {
        if(nums[s] == nums[e]) 
        {
            s += 2;
            e += 2;
        }
        else return nums[s];
    }
    if(s<n) return nums[s];
    return -1;
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