#include<bits/stdc++.h>
using namespace std;


int longest(vector<int>& nums)
{
    int n = nums.size();
    int length = 1;
    for(int i = 0; i<n; i++)
    {
        int sum = 0;
        for(int j= i; j <n; j++)
        {
            sum += nums[j];
            if(sum == 0)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // Assuming longest is a function that calculates the length of the longest subarray with sum k
    int length = longest(nums);
    cout << "The length of the longest subarray with sum 0 is: " << length << endl;
    return 0;
}