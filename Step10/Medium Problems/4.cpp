#include<bits/stdc++.h>
using namespace std; 

int characterReplacement(string s, int k){
    int n = s.length(); 
    int maxlen = 0; 
    for(int i = 0; i<n; i++){
        int hash[26] = {0}; 
        int maxfreq = 0; 
        for(int j = i; j<n; j++){
            hash[s[j] - 'A']++; 
            maxfreq = max(maxfreq, hash[s[j] -'A']); 
            int changes = (j-i+1) - maxfreq; 
            if(changes <= k) maxlen = max(maxlen, j-i+1); 
            else break; 
        }
    }
    return maxlen; 
}

int main(){
    string s = "AABABBA"; 
    int k = 1; 
    cout << "The length of the longest substring containing the same letter you can get after performing the k operations is : " << characterReplacement(s, k); 
    return 0; 
}