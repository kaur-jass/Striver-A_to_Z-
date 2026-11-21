#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0) return; // Handle empty array case
    if (k == 0) return; // No rotation needed if k is 0 or equal to array size
    reverse(nums.begin(), nums.end()); // Reverse the entire array
    reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements    
    reverse(nums.begin() + k, nums.end()); // Reverse the remaining elements

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
    int k;
    cin >> k;
    k = k % n; // Ensure k is within the bounds of the array size
    rotate(nums,k);
    for(int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}