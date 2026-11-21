#include<bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int>& nums) {
     int n = nums.size();
     map<int, int> freq;
     int maxF = 0;
     for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
     }
     for(auto it : freq)
     {
        if(it.second > maxF) maxF = it.first;
     }
     return maxF;
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
    cout << maxFrequency(nums)<< endl;
    return 0;
}