#include<bits/stdc++.h>
using namespace std;
int powerof2(int n){
    if(n<=0) return 0;
    return (n & (n-1));
}
int main(){
    int n; 
    cin >> n; 
    int ans = powerof2(n);
    if(ans == 0) cout << "Power of 2" << endl; 
    else cout << "Not a Power of 2" << endl;
    return 0;
}