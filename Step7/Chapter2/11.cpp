#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int index, vector<int>& ans,vector<vector<int>>& result, int k, int n){
        if(ans.size() == k && n == 0){
            result.push_back(ans);
        }
        if(ans.size() == k || n<0) return;
        for(int i = index; i<=9; i++){
            ans.push_back(i);
            generate(i+1,ans, result, k, n-i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans; 
        vector<vector<int>> result; 
        generate(1, ans, result, k , n); 
        return result; 
    }
};
int main(){
    Solution sol; 
    int k = 3; 
    int n = 7; 
    vector<vector<int>> result = sol.combinationSum3(k, n); 
    for(auto vec : result){
        cout<<"[ ";
        for(auto val : vec){
            cout<<val<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0; 
}