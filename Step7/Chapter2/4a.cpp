#include<bits/stdc++.h>
using namespace std;
bool flag = false; 
void generate(int index, vector<int> current, vector<int>& nums, int k, int sum){
    int n = nums.size(); 
    if(index == n){
        if(k == sum && flag == false){
            flag = true;
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
    sum -= nums[index];
    generate(index+1, current, nums, k, sum);
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