#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int start,vector<int>& candidates, int target, vector<vector<int>>& result,vector<int>& ans, int sum){
        int n = candidates.size();
        if(sum == target){
            result.push_back(ans);
            return;
        }
        if(sum > target || start == n) return;
        for(int i = start; i<n; i++){
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (sum + candidates[i] > target) break;
            ans.push_back(candidates[i]);
            generate(i+1, candidates, target, result,ans,sum+candidates[i]);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result; 
        vector<int> ans;
        generate(0, candidates, target, result,ans,0);
        return result; 
    }
};
int main(){
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    for(auto vec : result){
        cout<<"[ ";
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}