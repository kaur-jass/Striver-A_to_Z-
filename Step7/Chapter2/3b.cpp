#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int index, vector<int> current, vector<int>& nums){
        int n = nums.size(); 
        if(index >= n){
            cout<<"[ ";
            for(auto val : current){
                cout<<val<<" ";
            }
            cout<<"]"<<endl;
            return;
        }  
        current.push_back(nums[index]);
        generate(index+1, current, nums);
        current.pop_back();
        generate(index+1, current, nums);        
    }
    void subsets(vector<int>& nums) {
        int n = nums.size();
        generate(0,{},nums); 
    }
};


int main(){
    Solution sol; 
    vector<int> nums = {1,2,3}; 
    sol.subsets(nums); 
    return 0; 
}