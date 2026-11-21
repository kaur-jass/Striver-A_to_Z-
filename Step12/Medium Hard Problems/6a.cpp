#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); 
        int candies = n; // Start with 1 candy for each child
        int i = 1; 
        while(i<n){
            if(ratings[i] == ratings[i-1]){ 
                i++; 
                continue;
            }
            int peak = 0; 
            while(i<n && ratings[i] > ratings[i-1]){
                peak++; 
                candies += peak; 
                i++;
            }
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++; 
                candies += valley; 
                i++;
            }
            candies -= min(peak, valley); // remove the minimum of peak and valley to ensure the child at the peak gets enough candies
        }
        return candies;
    }
};
int main() {
    Solution ob;
    vector<int> ratings = {1,0,2};
    cout << ob.candy(ratings) << endl; // Output: 5
    return 0;
}