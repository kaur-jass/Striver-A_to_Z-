#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count = 0;
        while(ans != 0){
            ans = ans & (ans-1);
            count++;
        }
        return count;
    }
};
int main(){
    Solution sol; 
    int start = 10; 
    int goal = 7; 
    cout<<sol.minBitFlips(start, goal)<<endl; 
    return 0;
}