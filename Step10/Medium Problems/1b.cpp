#include<bits/stdc++.h>
using namespace std; 
int lengthOfLongestSubstring(string s) {
    int maxlen = 0; 
    int n = s.length();
    vector<int> hash(256, -1);
    int l = 0; 
    int r = 0; 
    while(r<n){
        if(hash[s[r]] != -1){
            l = max(hash[s[r]]+1, l);
        }
        maxlen = max(maxlen, r-l+1);
        hash[s[r]] = r; 
        r++;      
    }
    return maxlen; 
}
int main(){
    string s = "abcabcbb"; 
    int ans = lengthOfLongestSubstring(s); 
    cout << ans; 
    return 0; 
}