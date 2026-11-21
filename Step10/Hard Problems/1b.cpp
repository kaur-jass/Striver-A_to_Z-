// Problem Statement: Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters

// Input :s = "aababbcaacc" , k = 2
// Output :6
// Explanation :The longest substring with at most two distinct characters is "aababb".
// The length of the string 6


// Input : s = "abcddefg" , k = 3
// Output : 4
// Explanation : The longest substring with at most three distinct characters is "bcdd".
// The length of the string 4.

#include<bits/stdc++.h>
using namespace std; 

int distcharc(string s, int k){
    int maxlen = 0;
    int l = 0, r= 0; 
    unordered_map<char, int> mpp; 
    while(r<s.size()){
        mpp[s[r]]++; 
        if(mpp.size()>k){
            mpp[s[l]]--; 
            if(mpp[s[l]] == 0) mpp.erase(s[l]); 
            l++; 
        }
        if(mpp.size() <= k) maxlen = max(maxlen, r-l+1); 
        r++; 
    }
    return maxlen; 
}
int main(){
    string s = "abcddefg"; 
    int k = 3; 
    cout << " The length of the longest substring with at most" << k << " distinct characters is : " << distcharc(s,k);
    return 0; 
}