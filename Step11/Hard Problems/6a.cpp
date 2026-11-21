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
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap; 
        for(auto it : freq){
            minheap.push({it.second, it.first});  // Sorting by frequency not by number or keys... 
            if(minheap.size()>k){
                minheap.pop(); 
            }
        } 
        while(!minheap.empty()){
            pair<int, int> pr = minheap.top(); 
            minheap.pop(); 
            ans.push_back(pr.second); // Push Key not frequency.... 
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