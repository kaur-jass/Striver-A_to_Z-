#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> ans; 
        unordered_map<int, int> freq; 
        for(int num : nums)
        {
            freq[num]++;
        }
        vector<pair<int,int>> temp; 
        for(auto it: freq)
        {
            temp.push_back({it.first, it.second}); 
        }
        sort(temp.begin(), temp.end(),[](auto &a, auto &b){
            return a.second>b.second;
        });
        for(int i = 0; i<k && i<(int)temp.size(); i++){
            ans.push_back(temp[i].first);
        }
        return ans; 
    }
};
int main(){
    Solution s; 
    vector<int> nums = {1,1,1,2,2,3}; 
    int k = 2; 
    vector<int> ans = s.topKFrequent(nums, k); 
    for(int num: ans){
        cout<<num<<" "; 
    }
    cout<<endl; 
    return 0; 
}