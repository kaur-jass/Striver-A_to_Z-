#include<bits/stdc++.h>
using namespace std; 

int characterReplacement(string s, int k){
    int n = s.length(); 
    int maxlen = 0; 
    int maxfq = 0; 
    int hash[26]= {0};
    int r = 0; 
    int l = 0; 
    while(r<n){
        hash[s[r] - 'A']++; 
        maxfq = max(maxfq,hash[s[r] - 'A']); 
        if(r-l+1 - maxfq > k){
            hash[s[l] - 'A']--; 
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