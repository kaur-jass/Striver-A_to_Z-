#include<bits/stdc++.h>
using namespace std; 

vector<vector<int>> FindPrimes(vector<int>& nums){
    vector<vector<int>> ans; 
    for(int i = 0; i< nums.size(); i++){
        int n = nums[i]; 
        vector<int> temp; 
        for(int j = 2; j*j <= n; j++){
            while(n%j == 0){
                temp.push_back(j); 
                n = n/j; 
            }
        }
        if(n > 1){
            temp.push_back(n); 
        }
        ans.push_back(temp); 
    }
    return ans;
}

int main(){
    vector<int> nums = {7,12,18};
    vector<vector<int>> result;
    result = FindPrimes(nums);
    cout << "The prime factors are : "<<endl;
    cout<<"["; 
    for(int i = 0; i<result.size(); i++){
        cout<<"[";
        for(int j = 0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout <<"]" << " ";
    }
    
    cout<<"]";
    return 0;
}