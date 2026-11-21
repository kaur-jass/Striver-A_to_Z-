#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int substrings(string s) {
        int l = s.length();
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            int mask = 0;
            for (int j = i; j < l; j++) {
                int idx = s[j] - 'a';
                mask ^= (1 << idx);
                if ((mask & (mask - 1)) == 0) cnt++;
            }
        }

    return cnt;
}

};

int main() {
    Solution sol;
    string s = "ababa";
    cout << sol.substrings(s) << endl;
    return 0;
}
