#include<bits/stdc++.h>
using namespace std;

 #include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target, int s, int e) {
    int n = nums.size();
    if(s > e) return -1;
    int mid = s + (e - s) / 2;
    if(nums[mid] == target)
    {
        return mid;
    }
    else if(nums[mid] > target)
    {
        return search(nums, target, s, e-1);
    }
    else
    {
         return search(nums, target, mid+1, e);
    }  
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
    int target;
    cin >> target;
    int low = 0;
    int high = n-1;
    cout << search(nums, target, low, high) << endl;
    return 0;
}