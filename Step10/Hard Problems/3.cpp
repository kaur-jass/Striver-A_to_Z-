#include<bits/stdc++.h>
using namespace std; 

string minWindow(string s, string t){
    int m = s.length(); 
    int n = t.length();
    vector<int> hash(256, 0); 
    for(int i = 0;i<n; i++){
        hash[t[i]]++; 
    } 
    int l = 0; 
    int r = 0; 
    int i = 0; 
    int minlen = INT_MAX; 
    int currlen = 0; 
    int req = t.length(); 
    vector<int> hash2(256,0); 
    while(r<m){
        hash2[s[r]]++;
        currlen++;  
        // Expanding the window
        if(hash[s[r]]>0 && hash2[s[r]] <= hash[s[r]]){
            req--; 
        }
        while(req == 0){ // s windowscontains all characters with req freq 
            if(currlen < minlen){
                minlen = currlen; 
                i = l; 
            }
            hash2[s[l]]--; 
            currlen--;
            // shrinking window 
            if(hash[s[l]] > 0 && hash[s[l]] > hash2[s[l]]){
                req++;     
            }
            l++; 
        }            
        r++; 
    }
    return minlen == INT_MAX ? "" : s.substr(i,minlen);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "The substring with minWindow is : " << minWindow(s, t); 
    return 0;
}