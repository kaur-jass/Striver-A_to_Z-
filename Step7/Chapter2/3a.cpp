#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, int j){
        int n = nums.size();
        int n1 = ans.size(); 
        if(n == j){
            return;
        }  
        for(int k = j; k<n; k++){
            ans.push_back(nums[k]);
            result.push_back(ans);
            generate(nums, result, ans, k+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> result; 
        result.push_back({});
        for(int i = 0; i<n; i++){
            vector<int> ans;
            ans.push_back(nums[i]); 
            result.push_back(ans); 
            generate(nums, result, ans, i+1); 
        }
        return result;  
    }
};


int main(){
    Solution sol; 
    vector<int> nums = {1,2,2}; 
    vector<vector<int>> result = sol.subsets(nums); 
    for(auto vec : result){
        cout<<"[ ";
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0; 
}