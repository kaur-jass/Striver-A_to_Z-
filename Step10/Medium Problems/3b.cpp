#include<bits/stdc++.h>
using namespace std; 
int fruitsintobasket(vector<int>& nums) {
    int n = nums.size(); 
    int maxlen = 0; 
    for(int i = 0; i<n; i++){
        set<int> st; 
        for(int j = i; j<n; j++){
            st.insert(nums[j]); 
            if(st.size()<= 2) maxlen = max(maxlen, j-i+1); 
            else break; 
        }
    }
    return maxlen; 
}
int main(){
    vector<int> nums = {1,2,1,3,3,3,1,2}; 
    cout << "Ans is : " << fruitsintobasket(nums); 
    return 0; 
}