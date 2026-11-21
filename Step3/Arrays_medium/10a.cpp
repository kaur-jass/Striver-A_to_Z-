#include<bits/stdc++.h>
using namespace std;
// if array doesnot contain duplicate elements 
int sequence(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = 1;
    int length;
    int ans = 1;
    for(int i = 0;i <n; i++)
    { 
        if(nums[left]+1 == nums[right])
        {
            left++;
            right++;
            ans++;
        }
        else{
            length = ans;
            break;
        }
    }
    return length;
}
int main() {  
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << sequence(nums) << endl;
    return 0;
}