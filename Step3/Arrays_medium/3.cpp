#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(nums[i] == nums[j]) cnt++;
        }
        if(cnt > n/2) return nums[i];
    }
    return -1; // This line is just a fallback, ideally we should not reach here if the input guarantees a majority element.
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