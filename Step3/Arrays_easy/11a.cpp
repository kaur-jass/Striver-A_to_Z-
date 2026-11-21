#include<bits/stdc++.h>
using namespace std;
int max_one(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int maxi = 1;
    for(int i = 0; i<n ; i++)
    {
        if(nums[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
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
    int result = max_one(nums);
    cout << "Maximum number of consecutive 1's: " << result << endl;
    return 0;
}