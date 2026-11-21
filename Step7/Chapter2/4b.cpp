#include<bits/stdc++.h>
using namespace std;

bool generate(int index, vector<int> current, vector<int>& nums, int k, int sum){
    int n = nums.size(); 
    if(index == n){
        // Condition Satisfied
        if(k == sum){
            cout<<"[ ";
            for(auto val : current){
                cout<<val<<" ";
            }
            cout<<"]"<<endl;
            return true;
        }
        return false;
    }  
    current.push_back(nums[index]);
    sum += nums[index];
    if(generate(index+1, current, nums, k, sum)) return true;
    current.pop_back();
    sum -= nums[index];
    if(generate(index+1, current, nums, k, sum)) return true;
    return false;
}
void subsets(vector<int>& nums, int k){
    int n = nums.size();
    generate(0,{},nums,k,0);
}


int main(){
    int k;
    cout<<"Enter the value of k: "; 
    cin>>k;
    vector<int> nums = {1,2,1};
    subsets(nums,k);
    return 0;
}