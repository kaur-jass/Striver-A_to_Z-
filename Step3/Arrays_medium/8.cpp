#include<bits/stdc++.h>
using namespace std;
 int findindex(map<int, vector<int>>& mpp, vector<int>& target)
    {
        for(auto& pair : mpp)
        {
            if(pair.second == target)
            return pair.first;
        }
        return -1;
    }
void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        sort(nums.begin(),nums.end());
        map<int, vector<int>> mpp;
        int idx = 0;
        do{
            mpp[idx] = nums;
            idx++;
        }while(next_permutation(nums.begin(),nums.end()));
        int input_index = findindex(mpp, target);
        int result = input_index+1;
        if(mpp.find(result) != mpp.end())
        {
            for(int num : mpp[result])
            {
                cout << num << " ";
            }
        }
        else
        {
            for(int num : mpp[0])
            {
                cout << num << " ";
            }
        }
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    return 0;
}