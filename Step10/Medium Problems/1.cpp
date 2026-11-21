#include<bits/stdc++.h>
using namespace std; 
int lengthOfLongestSubstring(string s) {
    size_t len = 0; 
    for(int i = 0 ; i<s.length(); i++){
        string st = ""; 
        for(int j = i; j<s.length(); j++){
            if(find(st.begin(), st.end(), s[j]) == st.end()){
                st += s[j]; 
            }
            else break; 
        }
        len = max(st.length(), len); 
    }
    return len; 
}
int main(){
    string s = "abcabcbb"; 
    int ans = lengthOfLongestSubstring(s); 
    cout << ans; 
    return 0; 
}