#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> hash(n,1);
        for(int i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                hash[i] = hash[i-1] + 1;
            }
        }
        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                hash[i] = max(hash[i], hash[i+1]+1);
            }
        }
        int ans = 0; 
        for(int it : hash){
            ans += it; 
        }
        return ans; 
    }
};
int main() {
    Solution ob;
    vector<int> ratings = {1,0,2};
    cout << ob.candy(ratings) << endl; // Output: 5
    return 0;
}