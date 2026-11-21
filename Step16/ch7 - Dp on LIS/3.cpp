#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp; 
        int len = 0; 
        for(int i = 0; i<n; i++){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            if(it == temp.end()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                *it = nums[i];
            }
        }
        for(int i=0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
        }
        cout << endl;
        return len; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int len = sol.lengthOfLIS(nums);
    cout << "Length of LIS: " << len << endl;
    return 0;
}