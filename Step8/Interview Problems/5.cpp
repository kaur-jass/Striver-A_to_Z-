#include<bits/stdc++.h>
using namespace std;

vector<int> findUnique(vector<int> nums){
    int n = nums.size();
    unordered_map<int, int> freq;
    for(int i = 0; i<n; i++){
        freq[nums[i]]++;
    }   
     vector <int> ans;
    for(auto it: freq){
        if(it.second == 1){
            ans.push_back(it.first);
        }
    }
    sort(ans.begin(), ans.end());   
    return ans; 
}

int main(){
    vector<int> nums = {1,2,1,3,5,2};
    vector<int> ans = findUnique(nums); 
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}