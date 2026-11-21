#include<bits/stdc++.h>
using namespace std;

int Count(vector<int> &nums, int target)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for(int j = i; j<n;j++)
        {  
            k = k ^ nums[j];
            if(k == target)
            {
                count++;
            }
            else if(k<target)
            {
                continue;
            }
        }   
    }
    return count;
    
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    // This will calculate how many subarrays are present having xor equals to the target 
    int length = Count(nums,target);
    cout << length << endl;
    return 0;
}