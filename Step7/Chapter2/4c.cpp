#include<bits/stdc++.h>
using namespace std;

int generate(int index, vector<int> current, vector<int>& nums, int k, int sum){
    int n = nums.size(); 
    // condition not satisfied
    // strictly satisfied only for positive numbers
    if(sum > k) return 0;
    if(index == n){
        // Condition Satisfied
        if(k == sum){
            cout<<"[ ";
            for(auto val : current){
                cout<<val<<" ";
            }
            cout<<"]"<<endl;
            return 1;
        }
        return 0;
    }  
    current.push_back(nums[index]);
    sum += nums[index];
    int lcount = generate(index+1, current, nums, k, sum);
    current.pop_back();
    sum -= nums[index];
    int rcount = generate(index+1, current, nums, k, sum);
    int count = lcount + rcount;
    return count;
}
void subsets(vector<int>& nums, int k){
    int n = nums.size();
    int count = generate(0,{},nums,k,0);
    if(count == 0){
        cout<<"No subset found with the given sum k"<<endl;
    }
    cout<< "The no. of subsets with the given sum k are "<<count<<endl;
}


int main(){
    int k;
    cout<<"Enter the value of k: "; 
    cin>>k;
    vector<int> nums = {1,2,1};
    subsets(nums,k);
    return 0;
}