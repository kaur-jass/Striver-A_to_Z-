#include<bits/stdc++.h>
using namespace std;
bool ls(vector<int>& nums, int x){
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == x)
            return true;
    }
    return false;
}
int sequence(vector<int>& nums) {
    int n = nums.size();
    int longest = 1;
    for(int i=0; i<n; i++)
    {
        int x = nums[i];
        int cnt = 1;
        while(ls(nums,x+1) == true);
        {
            x++;
            cnt++;
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