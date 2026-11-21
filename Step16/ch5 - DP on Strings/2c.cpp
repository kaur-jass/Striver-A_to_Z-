#include<bits/stdc++.h>
using namespace std;

// using space optimization to find the longest common subsequence string4
class Solution {
    vector<string> prev, curr;
public:
    string lcs(string s, string t){
        int n = s.length(); 
        int m = t.length();
        // using standard table filling approach to find the longest common subsequence string
        prev.assign(m+1, "");
        for(int i = 0; i <= n; i++){
            curr.assign(m+1, "");
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0) curr[j] = "";
                else if(s[i-1] == t[j-1]) curr[j] = prev[j-1] + s[i-1];
                else curr[j] = (prev[j].size() >= curr[j-1].size() ? prev[j] : curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main(){
    string s, t; 
    cin >> s >> t; 
    Solution obj; 
    cout << obj.lcs(s, t) << endl; 
    return 0; 
}
