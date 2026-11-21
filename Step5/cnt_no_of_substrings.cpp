#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int substrings(string s){
        int l = s.length(); 
        int cnt = 0; 
        for(int i = 0; i<l; i++){
            unordered_map<char, int> mp;
            for(int j = i; j<l; j++){
                mp[s[j]]++;  
                int odd_cnt = 0; 
                for(auto it : mp){
                    if(it.second%2) odd_cnt++; 
                }
                if(odd_cnt<=1) cnt++; 
            }
        }
        return cnt; 
    }
}; 

int main() {
    Solution sol;
    string s = "ababa";
    // cin >> s;
    cout << sol.substrings(s) << endl;
    return 0;
}
