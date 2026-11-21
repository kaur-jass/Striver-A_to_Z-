#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size(); 
        if(k == 1) return nums[0]; 
        if(k == 2){
            long long ans = LLONG_MAX; 
            for(int i = 1; i<n; i++){
                ans = min(ans, 1ll*nums[0]+nums[i]); 
            }
            return ans; 
        } 
        long long mincost = LLONG_MAX; 
        for(int i = 1; i<n; i++){
            long long cost = nums[0] + nums[i]; 
            priority_queue<int> maxheap; 
            priority_queue<int, vector<int>, greater<int>> minheap;  
            for(int j = i+1; j<=min(i+dist, n-1); j++){
                minheap.push(nums[j]);
            }
            if(minheap.size()<k-2) continue; 
            while(!minheap.empty()){
                if(maxheap.size()<k-2){
                    maxheap.push(minheap.top()); 
                    minheap.pop(); 
                }
                else if(maxheap.top() > minheap.top()){
                    // swap(minheap.top(), maxheap.top())
                    // minheap.top() and maxheap.top() return const references.
                    // In C++, std::swap needs to modify the variables you pass into it, 
                    // but since you can't modify the top of a heap directly (that would
                    // break the heap structure), the compiler is throwing a fit.
                    int mintop = minheap.top(); 
                    int maxtop = maxheap.top(); 
                    minheap.pop(); 
                    maxheap.pop(); 
                    minheap.push(maxtop); 
                    maxheap.push(mintop); 
                }
                else break; 
            }
            while(!maxheap.empty()){
                cost += maxheap.top(); 
                maxheap.pop();
            }
            mincost = min(cost, mincost); 
       }  
       return mincost;   
    }
};

int main()
{
    Solution sol; 
    vector<int> nums = {1,3,5,2,8,4,6}; 
    int k = 3; 
    int dist = 2; 
    cout << sol.minimumCost(nums, k, dist) << " ";
    return 0;
}