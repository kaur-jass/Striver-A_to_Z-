#include <bits/stdc++.h>
using namespace std;


vector<int> findDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    vector<int> primeDivisors;

    for (int d : divisors) {
        if (d <= 1) continue;   // 0 and 1 are not prime

        bool isPrime = true;
        for (int j = 2; j * j <= d; j++) {
            if (d % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primeDivisors.push_back(d);
        }
    }
    return primeDivisors;
}
int main(){
    int n; 
    cin>>n;
    vector<int> ans = findDivisors(n);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
 