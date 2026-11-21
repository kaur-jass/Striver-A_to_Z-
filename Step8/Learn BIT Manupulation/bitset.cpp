#include <bits/stdc++.h>
using namespace std;

int main() {
    int k = 3;

    for (int i = 0; i < (1 << k); i++) {
        bitset<3> b(i);   // 3 = k
        cout << b << endl;
    }
}