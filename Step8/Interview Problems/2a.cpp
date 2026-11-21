#include<bits/stdc++.h>
using namespace std;

int findUnique(vector<int> nums){
    int xorno = 0;
    for(int num : nums){
        xorno ^= num;
    }                 
    return xorno;  
}

int main(){
    vector<int> nums = {1,2,1,3,2};
    int ans = findUnique(nums); 
    cout<<ans<<endl;
    return 0;
}