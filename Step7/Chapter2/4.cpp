#include<bits/stdc++.h>
using namespace std;

void generate(int index, vector<int> current, vector<int>& nums, int k, int sum){
    int n = nums.size(); 
    if(index == n){
        if(k == sum){
            cout<<"[ ";
            for(auto val : current){
                cout<<val<<" ";
            }
            cout<<"]"<<endl;
        }
        return;
    }  
    current.push_back(nums[index]);
    sum += nums[index];
    generate(index+1, current, nums, k, sum);
    current.pop_back();
    generate(index+1, current, nums, k, sum);
}
void subsets(vector<int>& nums, int k){
    int n = nums.size();
    generate(0,{},nums,k,0);
}


int main(){
    int k;
    k = 8;
    vector<int> nums = {10,1,2,7,6,1,5};
    subsets(nums,k);
    return 0;
}