#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> prev, curr; 
public:
    int unbounded_knapsack(int maxWeight, vector<int>& weight, vector<int>& value) {
        int n = weight.size();
        prev.assign(maxWeight + 1, 0);
        curr.assign(maxWeight + 1, 0);
        for(int W=0; W<=maxWeight; W++){
            if(weight[0] <= W)
                prev[W] = (int)(W / weight[0]) * value[0];
            else
                prev[W] = 0; 
        }
        for(int idx=1; idx<n; idx++){
            for(int W=0; W<=maxWeight; W++){
                int dont_pick = prev[W]; 
                int pick = INT_MIN; 
                if(weight[idx]<=W) pick = value[idx] + curr[W-weight[idx]];
                curr[W] = max(pick, dont_pick); 
            }
            prev = curr;
        }
        return prev[maxWeight];        
    }
}; 

int main(){
    int n, maxWeight; 
    cin >> n >> maxWeight; 
    vector<int> weight(n), value(n); 
    for(int i=0; i<n; i++) cin >> weight[i]; 
    for(int i=0; i<n; i++) cin >> value[i]; 
    Solution obj; 
    cout << obj.unbounded_knapsack(maxWeight, weight, value) << endl; 
    return 0; 
}