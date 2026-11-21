#include<bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos,neg;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] > 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    if(pos.size() > neg.size())
    {
        for(int i = 0; i <neg.size(); i++)
        {
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int index = neg.size();
        for(int i = index; i < pos.size(); i++)
        {
            nums[index] = pos[i];
            index++;
        }
    }
    else
    {
        for(int i = 0; i <pos.size(); i++)
        {
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int index = pos.size();
        for(int i = index; i < neg.size(); i++)
        {
            nums[index] = neg[i];
            index++;
        }
    }
    return nums;
}

int main() {
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> result = rearrangeArray(nums);
    cout << "Rearranged array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}