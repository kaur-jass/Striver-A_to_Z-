#include<bits/stdc++.h>
using namespace std;
int sequence(vector<int>& nums) {
    int n = nums.size();
     if(n == 0) return 0;
    sort(nums.begin(), nums.end());
    int lastsmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i=0; i<n; i++)
    {
        if(nums[i]-1 == lastsmaller)
        {
            cnt++;
            lastsmaller = nums[i];
        }
        else{
            cnt = 1;
            lastsmaller = nums[i]; 
        }

        longest = max(longest, cnt);
    }
    return longest;
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