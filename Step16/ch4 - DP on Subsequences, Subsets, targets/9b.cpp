#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> prev, curr; 
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        prev.assign(amount + 1, 0);
        curr.assign(amount + 1, 0);
        for(int T=0; T<=amount; T++) prev[T] = (T % coins[0] == 0) ? 1 : 0;
        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=amount; T++){
                int dont_pick = prev[T]; 
                int pick = 0; 
                if(coins[idx]<=T) pick = curr[T-coins[idx]];
                curr[T] = pick + dont_pick; 
            }
            prev = curr;
        }
        return prev[amount]; 
    }
};

int main(){
    int n, amount; 
    cin >> n >> amount; 
    vector<int> coins(n); 
    for(int i=0; i<n; i++) cin >> coins[i]; 
    Solution obj; 
    cout << obj.change(amount, coins) << endl; 
    return 0; 
}