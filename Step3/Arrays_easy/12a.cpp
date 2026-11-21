#include<bits/stdc++.h>
using namespace std;

int different_element(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0) return -1; // Handle empty array case
    // Using unordered_map to count frequency of each element
   unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    for(auto it : mpp)
    {
        if(it.second == 1)
        {
            return it.first; // Return the first element with frequency 1
        }
    }
    return -1; // If no unique element found, return -1
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = different_element(nums);
    cout << "The different element in the array is : " << result << endl;
    return 0;
}