#include<bits/stdc++.h>
using namespace std;


int longest_k(vector<int>& nums, int k)
{
    int n = nums.size();
    int maxlen = 0; 
    int sum = 0; 
    unordered_map<long long, int> prefixSumMap;
    for(int i = 0; i<n ;i++){
        sum += nums[i]; 
        if(sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        int rem = sum-k;
        if(prefixSumMap.find(rem) != prefixSumMap.end())
        {
            int len = i - prefixSumMap[rem];
            maxlen = max(maxlen, len);
        }
        // Store the first occurrence of this sum
        if(prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i; 
        }
    }
    return maxlen;
}


int longest(vector<int>& nums)
{
    int n = nums.size();
    int maxlen = 0;
    int sum = 0;
    unordered_map<long long, int> prefixSumMap;
    for(int i =0; i<n ; i++) {   
        sum += nums[i];
        if(sum == 0)
        {
            maxlen = max(maxlen, i + 1);
        }
        int rem = sum-0;
        if(prefixSumMap.find(rem) != prefixSumMap.end())
        {
            int len = i- prefixSumMap[rem];
            maxlen = max(maxlen, len);
        }

        if(prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i; // Store the first occurrence of this sum
        }
   }   
    return maxlen;
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