#include<bits/stdc++.h>
using namespace std;


int longest(vector<int>& nums, int k)
{
    int n = nums.size();
    int cnt= 0;
    for(int i = 0; i<n; i++)
    {
        int sum = 0;
        for(int j= i; j <n; j++)
        {
            sum += nums[j];
            if(sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
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
    // Assuming longest is a function that calculates the length of the longest subarray with sum k
    int length = longest(nums, k);
    cout << "The length of the longest subarray with sum " << k << " is: " << length << endl;
    return 0;
}