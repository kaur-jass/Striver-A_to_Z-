#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ele = INT_MAX; 
        int profit = 0; 
        for(int price : prices){
            min_ele = min(min_ele, price); 
            profit = max(profit, price - min_ele); 
        }
        return profit; 
    }
};
int main(){
    Solution s; 
    vector<int> prices = {7,1,5,3,6,4}; 
    cout << s.maxProfit(prices) << endl; 
    return 0; 
}