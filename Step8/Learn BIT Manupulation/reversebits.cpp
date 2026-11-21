#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;
            ans |= (bit << (31 - i));
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.reverseBits(n) << endl;
    return 0;
}