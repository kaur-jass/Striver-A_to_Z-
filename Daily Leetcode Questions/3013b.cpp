#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size(); 
        // Edge Cases - 
        if(k == 1) return nums[0]; 
        if(k == 2){
            long long ans = LLONG_MAX; 
            for(int i = 1; i<n; i++){
                ans = min(ans, 1ll*nums[0]+nums[i]); 
            }
            return ans; 
        } 
        // key properties of multiset
        //  -> Multiset is always sorted 
        //  -> MUltiset allows duplicates
        multiset<int> chosen;  // k-2 smallest  - window 
        multiset<int> remaining;   // rest of the window 
        long long sumchosen = 0; 

        // Initial window for i = 1 -> i, ndices[2....2+dist]
        for(int j = 2; j <= min(1+dist, n-1); j++){
            remaining.insert(nums[j]);
        }

        // Move Smallest k-2 elements to chosen 
        while(chosen.size()<k-2 && !remaining.empty()){
            auto it = remaining.begin(); 
            chosen.insert(*it); 
            sumchosen += *it; 
            remaining.erase(it); 
        }

        long long ans = LLONG_MAX; 
        

        // Slide i from 1 to n-1 
        for(int i = 1; i<n; i++){
            // Remove the outgoing element (i+1)
            if(i>1){
                // remove outgoing
                int out = nums[i]; 
                auto it = chosen.find(out);
                if (it != chosen.end()) {
                    sumchosen -= out;
                    chosen.erase(it);
                } else {
                    auto it2 = remaining.find(out);
                    if (it2 != remaining.end()) {
                        remaining.erase(it2);
                    }
                }
            }

            // Add incoming elements
            if (i > 1 && i + dist < n) {
                remaining.insert(nums[i + dist]);
            }


            // Rebalance it 
            while(chosen.size()<k-2 && !remaining.empty()){
                auto it = remaining.begin(); 
                chosen.insert(*it); 
                sumchosen += *it; 
                remaining.erase(it); 
            }
            
            // Rebalance order
            while (!chosen.empty() && !remaining.empty() && *prev(chosen.end()) > *remaining.begin()) {
                int a = *prev(chosen.end());
                int b = *remaining.begin();

                chosen.erase(prev(chosen.end()));
                remaining.erase(remaining.begin());

                chosen.insert(b);
                remaining.insert(a);

                sumchosen += b - a;
            }
            // Check if we can form k elements 
            if(chosen.size() == k-2){
                long long cost = nums[0] + nums[i] +sumchosen; 
                ans = min(ans, cost); 
            }
        }
        return ans;         
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