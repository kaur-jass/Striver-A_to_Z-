#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int index, vector<int> current, vector<int>& nums, vector<vector<int>>& result){
        int n = nums.size(); 
        result.push_back(current);
        // if(index >= n){
        //     return;            No need for writing Base Case cause of the for loop
        // }
        for(int i = index; i<n; i++){
            if (i > index && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            generate(i+1, current, nums, result);
            current.pop_back();
        }
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        generate(0, {}, nums, result);
        return result;
    }
};

int main(){
    Solution sol; 
    vector<int> nums = {1,2,2}; 
    vector<vector<int>> result = sol.subsetsWithDup(nums); 
    for(auto vec : result){
        cout<<"[ ";
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0; 
}