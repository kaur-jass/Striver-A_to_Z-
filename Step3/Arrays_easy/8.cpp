#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &nums, int k)
{
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        if(nums[i] == k) return i;
    }
    return -1;
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
    int result = linear_search(nums, k);
    if(result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}