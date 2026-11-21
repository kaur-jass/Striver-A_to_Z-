#include<bits/stdc++.h>
using namespace std;
int oddoreven(int n){
    return (n & 1);
}
int main(){
    int n; 
    cin >> n; 
    int ans = oddoreven(n);
    if(ans == 0) cout << "Even" << endl; 
    else cout << "Odd" << endl;
    return 0;
}