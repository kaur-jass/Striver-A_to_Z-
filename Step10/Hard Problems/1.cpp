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
    for(int i = 0; i< s.length(); i++){
        unordered_map<char, int>  mpp; 
        for(int j = i; j<s.length(); j++){
            mpp[s[j]]++;
            // if(mpp.size() <= k ){
            //     maxlen = max(maxlen, j-i+1); 
            // }
            // else break; 
            if(mpp.size()>k) break; 
            maxlen = max(maxlen, j-i+1); 
        }
    }
    return maxlen; 
}
int main(){
    string s = "abcddefg"; 
    int k = 3; 
    cout << " The length of the longest substring with at most" << k << " distinct characters is : " << distcharc(s,k);
    return 0; 
}