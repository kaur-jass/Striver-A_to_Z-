#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int index, vector<int> current, vector<int>& nums, vector<vector<int>>& result){
        int n = nums.size(); 
        if(index >= n){
            if(find(result.begin(),result.end(),current)==result.end())
                result.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        generate(index+1, current, nums, result);
        current.pop_back();
        generate(index+1, current, nums, result);
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        result.push_back({}); 
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