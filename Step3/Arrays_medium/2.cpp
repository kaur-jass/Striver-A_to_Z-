#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int didswap = 0;
    for(int i = n-1;i >=1;i--)
    {
        for(int j = 0; j<= i-1;j++)
        {
            if(nums[j]>nums[j+1]) 
            {
                swap(nums[j],nums[j+1]);
                didswap = 1;
            }
        }
        if(didswap = 0) break;
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sortColors(nums);
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}