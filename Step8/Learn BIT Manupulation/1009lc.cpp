#include<bits/stdc++.h>
using namespace std;
int bitwiseComplement(int n) {
    if(n==0) return 1;
    int mask = 0, temp = n;
    while(temp){
        mask = (mask<<1) | 1;
        temp >>= 1;
    }
    return (~n) & mask;
}
int main(){
    int n; 
    cin>>n; 
    cout<<bitwiseComplement(n)<<endl; 
    return 0;
}