#include<bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int> &a) 
{
     next_permutation(a.begin(),a.end());
     return a;
}


int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int i = 0; i< nums.size(); i++)
    {
        cout<< nums[i]<< " ";
    }
    return 0;
}