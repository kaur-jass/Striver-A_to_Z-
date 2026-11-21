#include<bits/stdc++.h>
using namespace std;


string two_sum(vector<int> &nums, int target)
{
    int n= nums.size();
    int left = 0;
    int right = n - 1;
    sort(nums.begin(), nums.end());
    while(left < right)
    {
        int sum = nums[left] +nums[right];
        if(sum == target) return "Yes";
        else if (sum < target) left++;
        else right--;
    }
    return "No";
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << two_sum(nums, target);
    return 0;
}