#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        
    int n = prices.size();
    int max = 0;
        
    for(int i = n-1; i>=0;i--)
        
    {
            
        for (int j = i-1; j>=0; j--)
            
        {
                
            if((prices[i]-prices[j]) > max) 
                
            {
                   
                max = (prices[i]-prices[j]);
                
            }
            
        }
        
    }
        
    return max;
}
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}
