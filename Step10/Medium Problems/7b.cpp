#include<bits/stdc++.h>
using namespace std; 

int numberOfSubstrings(string s) {
    int n = s.length(); 
    int cnt = 0; 
    int lastseen[3] = {-1, -1, -1};
    for(int i = 0; i<n; i++){
        lastseen[s[i]-'a'] = i; 
        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
            cnt += min(lastseen[0], min(lastseen[1], lastseen[2])) + 1; 
        }
    }
    return cnt; 
}

int main(){
    string s = "abcabc"; 
    cout << "The No of substrings Containing all three characters are : " << numberOfSubstrings(s); 
    return 0; 
} 