#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& nums, int k)
{
    int n = nums.size();
    int s = 0;
    int e = n- 1;
    while(s<=e){
        // int mid = (s+e)/2;
        int mid = s + (e - s) / 2;  // Use this instead  //  In C++, int typically holds values up to around 2,147,483,647 (2^31 - 1).
                                                        // If s and e are large enough (like both close to 1e9), then s + e could overflow, causing:
                                                        // Unexpected negative mid values Or even runtime errors

        if(nums[mid] == k)
        {
            return mid;
        }
        else if(nums[mid] > k) e = mid - 1;
        else s = mid + 1;
    }
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
    int k;
    cin >> k;
    cout << "The index of the element is " << binary_search(nums, k) << endl;
    return 0;
}