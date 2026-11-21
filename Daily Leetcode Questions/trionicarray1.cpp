#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(); 
        if (n<4) return false; 
        int p = 0; 
        int q = 0; 
        for(int i = 0; i<n-1; i++){
            if(nums[i+1] < nums[i]){
                p = i; 
                break; 
            }
            else if(nums[i] == nums[i+1]) return false; 
        }
        for(int i = p+1; i<n-1; i++){
            if(nums[i+1] > nums[i]){
                q = i; 
                break; 
            }
            else if(nums[i] == nums[i+1]) return false; 
        }
        
        if(p>0 && q>p && q<n-1){
            for(int i = 0; i<p; i++){
                if(nums[i+1] <= nums[i]) return false;
                 
            }
            for(int i = p; i<q; i++){
                if(nums[i+1] >= nums[i]) return false; 
            }
            for(int i = q; i< n-1; i++){
                if(nums[i+1] <= nums[i]) return false; 

            }
            return true; 
        }
        return false;         
    }
};
int main()
{
    Solution sol; 
    vector<int> nums = {1,3,5,4,2,6}; 
    cout << sol.isTrionic(nums) << " ";
    return 0; 
}