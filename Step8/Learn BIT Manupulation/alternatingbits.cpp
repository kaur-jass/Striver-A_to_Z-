#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n ^ (n >> 1);
        return (x & (x+1)) == 0;
    }
};
int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << (sol.hasAlternatingBits(n) ? "true" : "false") << endl;
    return 0;
}