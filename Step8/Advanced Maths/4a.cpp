#include<bits/stdc++.h>
using namespace std; 
int MAX_N = 100000; 
vector<vector<int>> FindPrimes(vector<int>& nums){
    vector<int> spf(MAX_N + 1);
    for (int i = 0; i <= MAX_N; i++) {
        spf[i] = i;
    }
    for(int i = 2; i*i<=MAX_N; i++){
        if(spf[i]==i){
            for(int j = i*i; j<=MAX_N; j+=i){
                if(spf[j] == j) spf[j]=i; 
            }
        }
    } 
    vector<vector<int>> ans; 
    for(int i = 0; i<nums.size(); i++){
        int n  = nums[i]; 
        vector<int> temp; 
        while(n != 1){
            temp.push_back(spf[n]); 
            n = n/spf[n]; 
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