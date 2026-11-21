#include<bits/stdc++.h>
using namespace std;


int longest(vector<int>& nums, int k)
{
    int n = nums.size();
    int left = 0; 
    int right = 0;
    long long sum =  nums[0];
    int cnt = 0;
    while(right < n)
    {
        while(sum > k && left <= right)
        {
            sum -= nums[left];
            left++;
        }
        if(sum == k)
        {
            cnt++;
        }

        right++;
        if(right < n) {
            sum += nums[right];
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