#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
vector<int> findDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            divisors.push_back(i);
            if (i != n / i && isPrime(n / i)) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}


int main() {
    int n;
    cin >> n;
    vector<int> ans = findDivisors(n);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
