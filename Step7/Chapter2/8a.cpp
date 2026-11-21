#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int index,vector<int>& candidates, int target, set<vector<int>>& result,vector<int>& ans, int sum){
        int n = candidates.size();
        if(sum > target) return;
        if(index == n){
            if(sum == target){
                result.insert(ans);
                return;
            }
            return;
        }
        ans.push_back(candidates[index]);
        sum += candidates[index];
        generate(index+1, candidates, target, result,ans,sum);
        ans.pop_back();
        sum -= candidates[index];
        generate(index+1, candidates, target, result,ans,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> result; 
        vector<int> ans;
        generate(0, candidates, target, result,ans,0);
        return vector<vector<int>>(result.begin(), result.end()); 
    }
};
int main(){
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    for(auto vec : result){
        cout<<"[ ";
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}