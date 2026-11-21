#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int cnt = 0; 
        for (int i = 2; i <= n-1; i++) {
            if (isPrime(i)) {
                cnt++; 
            }
        }
        return cnt; 
    }
};
int main() {
    int n; 
    cin >> n; 
    Solution sol; 
    cout << sol.countPrimes(n) << endl; 
    return 0; 
}