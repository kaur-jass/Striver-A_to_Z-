// Problem Statement

// Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.
// If there is no such window in s1 that covers all characters in s2, return the empty string "".
// If there are multiple such minimum-length windows, return the one with the left-most starting index.

// Examples - 

// Example 1

// Input: s1 = "abcdebdde", s2 = "bde"
// Output: "bcde"

// Explanation:
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of s2 in the window must occur in order.

// Example 2

// Input: s1 = "jmeqsiwvaovvnbstl", s2 = "u"
// Output: ""

// Example 3

// Input: s1="fhhjkeejkdjjs", s2=”jkj”
// Output: jkdj

// Constraints
// 1 <= s1.length <= 2 * 104
// 1 <= s2.length <= 100
// s1 and s2 consist of lowercase English letters.

#include<bits/stdc++.h>
using namespace std; 

string minWind(string s, string t){
    int m = t.length(); 
    int n = s.length(); 
    int l = 0, j= 0; 
    while(l<n && s[l] != t[j]) l++; // mistake 1 - important check, what if l goes out of bounds 
    int r = l;
    int startidx = 0;  
    int minlen = INT_MAX;  
    while(r<n){
        if(s[r] == t[j]) j++;
        if(j == m){
            int k = r; 
            j = m-1; 
            while(j >= 0){
                if(s[k] == t[j]) j--; 
                k--;
            }
            l = k+1;
            if(r-l+1 < minlen){
                minlen = r-l+1; 
                startidx = l; 
            }
            // prepare for next search
            j = 0;
            r = l;   // important: restart forward scan 
        }
        r++; 
    }
    return minlen == INT_MAX ? "" : s.substr(startidx, minlen); 
}

int main(){
    string s = "fhhjkeejkdjjs"; 
    string t = "jkj"; 
    cout << "The substring with min Window Subsequence is : " << minWind(s,t); 
    return 0; 
}
