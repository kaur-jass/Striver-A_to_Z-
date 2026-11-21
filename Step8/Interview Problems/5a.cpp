#include<bits/stdc++.h>
using namespace std;

vector<int> findUnique(vector<int> nums){
    int n = nums.size();
    long long xorno = 0; 
    for(int i = 0; i<n; i++){
        xorno ^= nums[i];
    }
    long long rightmost = xorno & (-xorno);
    int num1 = 0, num2 = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] & rightmost){
            num1 ^= nums[i];
        }
        else{
            num2 ^= nums[i];
        }
    }
    if(num1 < num2){
        return {num1, num2};
    }
    return {num2, num1};
}

int main(){
    vector<int> nums = {1,2,1,3,5,2};
    vector<int> ans = findUnique(nums); 
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}