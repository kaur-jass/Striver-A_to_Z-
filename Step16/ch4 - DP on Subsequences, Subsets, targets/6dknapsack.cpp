#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int knapsack(int n, int W, vector<int> &wt, vector<int> &val){
        vector<int> prev(W+1, 0);
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= w) prev[w] = val[0]; 
            else prev[w] = 0; 
        }
        for(int idx=1; idx<n; idx++){
            for(int w=W; w>=0; w--){
                int notTake = 0 + prev[w]; 
                int take = INT_MIN; 
                if(wt[idx] <= w) take = val[idx] + prev[w-wt[idx]];
                prev[w] = max(take, notTake);
            }
        }
        return prev[W];
    }
};

int main(){
    int n, W; 
    cin >> n >> W; 
    vector<int> wt(n), val(n); 
    for(int i=0; i<n; i++) cin >> wt[i]; 
    for(int i=0; i<n; i++) cin >> val[i]; 
    Solution obj; 
    cout << obj.knapsack(n, W, wt, val) << endl; 
    return 0; 
}