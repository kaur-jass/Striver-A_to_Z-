#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool palindrome(string &s, int l, int r){
        while(l<=r){
            if(s[l]==s[r]){
                l++; r--; 
            }
            else return false; 
        }
        return true; 
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();  
        for (int r = n; r >= 1; r--) { 
            // 0 to len to substr
            for (int l = 0; l <= n - r; l++) { 
                if (palindrome(s, l, l + r - 1)) { 
                    return s.substr(l, r); 
                } 
            } 
        }
        return ""; 
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}