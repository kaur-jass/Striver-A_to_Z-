#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    int n = nums.size();
    for(int i = 0; i < n; i++) 
    {
        int num = nums[i];
        int moreneeded = target - num;
        if(mpp.find(moreneeded) != mpp.end())
        {
            return {mpp[moreneeded], i}; // Return the indices of the two numbers
        }
        mpp[num] = i;
    }
    return {};
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
    int k;
    cin >> k;
    vector<int> result = twoSum(nums, k);
    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "[]" << endl;
    }


    return 0;
}


