#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2= 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }
        for(int i = 0; i < cnt0; i++) nums[i] = 0;
        for(int i = cnt0; i < (cnt0+cnt1); i++) nums[i] = 1;
        for(int i = (cnt0+cnt1); i < n; i++) nums[i] = 2;
        
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