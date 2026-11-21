#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Brute Force 
        string s = ""; 
        string g = ""; 
        if (start == 0) s = "0";
        while(start > 0){
            if(start%2 == 1) s += '1'; 
            else s += '0'; 
            start = start/2; 
        }
        reverse(s.begin(), s.end());
        if (goal == 0) g = "0";
        while(goal > 0){
            if(goal%2 == 1) g += '1'; 
            else g += '0'; 
            goal = goal/2; 
        }
        reverse(g.begin(), g.end());
        int len1 = s.length(); 
        int len2 = g.length(); 
        if(len1 < len2) s = string(len2-len1,'0') + s; 
        else g = string(len1-len2,'0') + g; 
        int cnt = 0; 
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] != g[i]){ 
                cnt++; 
            } 
            else continue; 
        }
        return cnt;
    }
};
int main(){
    Solution sol; 
    int start = 10; 
    int goal = 7; 
    cout<<sol.minBitFlips(start, goal)<<endl; 
    return 0;
}