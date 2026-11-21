#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxind = 0; 
        int cnt = 0; 
        int rangeend = 0; 
        for(int i = 0; i<nums.size()-1; i++){  // If I am already at the last index, the journey is finished. No jump needed
            maxind = max(maxind,i+nums[i]);
            if(i == rangeend){
                cnt++;  // "I have reached the furthest place my last jump allowed me to go.  After this point, you cannot move even one step forward unless you jump again.
                rangeend = maxind;
            }
            if(cnt >=  nums.size()-1) return cnt;
        }
        return cnt; 
    }
};
int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    Solution s;
    cout<<s.jump(nums);
}