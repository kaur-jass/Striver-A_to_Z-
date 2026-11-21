#include<bits/stdc++.h>
using namespace std;

int findUnique(vector<int> nums){
    int n = nums.size();
    unordered_map<int, int> freq;
    for(int i = 0; i<n; i++){
        freq[nums[i]]++;
    }
    for(auto it: freq){
        if(it.second == 1){
            return it.first;    
        }
    }
    return -1;  
}

int main(){
    vector<int> nums = {1,2,1,3,2};
    int ans = findUnique(nums); 
    cout<<ans<<endl;
    return 0;
}