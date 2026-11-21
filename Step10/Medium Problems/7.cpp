#include<bits/stdc++.h>
using namespace std; 

int numberOfSubstrings(string s) {
    int n = s.length(); 
    int cnt = 0; 
    for(int i = 0; i<n; i++){
        unordered_map<char, int> mpp; 
        for(int j = i; j<n; j++){
            mpp[s[j]]++; 
            if(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                cnt += n-j;
                break; 
            }
        }
    }
    return cnt; 
}

int main(){
    string s = "abcabc"; 
    cout << "The No of substrings Containing all three characters are : " << numberOfSubstrings(s); 
    return 0; 
}