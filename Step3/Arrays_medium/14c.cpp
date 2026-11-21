#include<bits/stdc++.h>
using namespace std;


int longest(vector<int>& nums, long long k)
{
    unordered_map<int,int> mpp;
    int presum = 0;
    int cnt = 0;
    mpp[0] = 1;
    for(int i = 0; i<nums.size(); i++)
    {
        presum += nums[i];
        int remove = presum-k;
        cnt += mpp[remove];
        mpp[presum] += 1;
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
    cout << "The total Subarrays with sum " << k << " is: " << length << endl;
    return 0;
} 