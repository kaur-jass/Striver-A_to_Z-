#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // Optimal Approach 
        return __builtin_popcount(start^goal); 
    }
};
int main(){
    Solution sol; 
    int start = 10; 
    int goal = 7; 
    cout<<sol.minBitFlips(start, goal)<<endl; 
    return 0;
}