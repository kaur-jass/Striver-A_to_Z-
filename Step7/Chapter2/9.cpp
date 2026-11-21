#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sum(vector<int>& ans){
        int total = 0; 
        for(auto val : ans){
            total += val; 
        }
        return total; 
    }
    void generate(vector<int>& nums, vector<int>& result, vector<int>& ans, int j){
        int n = nums.size();
        int n1 = ans.size(); 
        if(n == j){
            return;
        }  
        for(int k = j; k<n; k++){
            ans.push_back(nums[k]);
            result.push_back(sum(ans));
            generate(nums, result, ans, k+1);
            ans.pop_back();
        }
    }
    vector<int> subsets(vector<int>& nums) {
        int n = nums.size(); 
       vector<int> result; 
        result.push_back(0);
        for(int i = 0; i<n; i++){
            vector<int> ans;
            ans.push_back(nums[i]); 
            result.push_back(sum(ans)); 
            generate(nums, result, ans, i+1); 
        }
        return result;  
    }
};


int main(){
    Solution sol; 
    vector<int> nums = {1,2,5}; 
    vector<int> result = sol.subsets(nums); 
    for(auto val : result){
        cout<<val<<" ";
    }
    return 0; 
}