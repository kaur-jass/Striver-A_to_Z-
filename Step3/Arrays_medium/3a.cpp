#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums)
{
    int n= nums.size();
    unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    int max = mpp[nums[0]];
    for(auto it : mpp)
    {
        if(it.second > max)
        {
            max = it.second;
        }
    }
    int ans;
    for(auto it : mpp)
    {
        if(it.second == max)
        {

            ans = it.first;
            break;
        }
    }
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << majorityElement(nums) << endl;
    return 0;
}