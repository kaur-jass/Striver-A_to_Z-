#include<bits/stdc++.h>
using namespace std; 
int lengthOfLongestSubstring(string s) {
    int maxlen = 0; 
    for(int i = 0 ; i<s.length(); i++){
        vector<int> hash(256, 0);
        int len = 0; 
        for(int j = i; j<s.length(); j++){
            if(hash[s[j]] == 1) break; 
            hash[s[j]] = 1; 
            len = j-i+1;
        }
        maxlen = max(maxlen, len); 
    }
    return maxlen; 
}
int main(){
    string s = "abcabcbb"; 
    int ans = lengthOfLongestSubstring(s); 
    cout << ans; 
    return 0; 
}