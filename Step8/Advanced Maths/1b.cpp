#include <bits/stdc++.h>
using namespace std;
vector<int> findDivisors(int n) {
    vector<int> divisors;
    int temp = n;
    for (int i = 1; i  <= temp; i++) {
        if (temp % i == 0 ) {
            divisors.push_back(i);
            while(temp % i == 0){
                temp = temp / i;
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
