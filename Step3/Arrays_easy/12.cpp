#include<bits/stdc++.h>
using namespace std;

int different_element(vector<int> &nums)
{
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        int cnt = 1;
        for(int j = 0; j<n; j++)
        {
            if(nums[j] == nums[i] && i != j) cnt++;
        }
        if(cnt == 1) return nums[i];
    }  
    return -1;
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
    int result = different_element(nums);
    cout << "The different element in the array is : " << result << endl;
    return 0;
}