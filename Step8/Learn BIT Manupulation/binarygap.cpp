#include<bits/stdc++.h>
using namespace std;
int binaryGap(int n) {
    int last = -1;
    int ans = 0;
    
    for(int i = 0; n > 0; i++) {
        if(n & 1) {
            if(last != -1)
                ans = max(ans, i - last);
            last = i;
        }
        n >>= 1;
    }
    return ans;
}
int main() {
    int n = 22; // Example input
    cout << "Binary gap for " << n << " is: " << binaryGap(n) << endl;
    return 0;
}