#include<bits/stdc++.h>
using namespace std; 

int characterReplacement(string s, int k){
    int n = s.length(); 
    int maxlen = 0; 
    unordered_map<char, int> mpp; 
    int l = 0; 
    int r = 0; 
    while(r<n){
        mpp[s[r]]++; 
        int maxfq = 0; 
        for(auto it: mpp){
            maxfq = max(maxfq,it.second); 
        }
        while((r-l+1) - maxfq >k){
            mpp[s[l]]--; 
            l++; 
        }
        maxlen = max(maxlen, r-l+1);
        r++; 
    }
    return maxlen; 
}

int main(){
    string s = "AABABBA"; 
    int k = 1; 
    cout << "The length of the longest substring containing the same letter you can get after performing the k operations is : " << characterReplacement(s, k); 
    return 0; 
}