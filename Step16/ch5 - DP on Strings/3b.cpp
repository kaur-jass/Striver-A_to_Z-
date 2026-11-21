#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prev, curr;
public:
    int longestCommonSubstring(string s, string t) {
        int n = s.size();
        int m = t.size();
        prev.assign(m+1, 0);
        curr.assign(m+1, 0);
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0; // if the characters are not equal, we cannot extend the substring, so we set it to 0
                }
            }
            prev = curr;
        }
        return ans;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.longestCommonSubstring(s, t) << endl;
    return 0;
}