#include<bits/stdc++.h>
using namespace std;
int func(int n){
    if(n%4 == 0) return n;
    else if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;    
    else if(n%4 == 3) return 0;
    return -1;
}
int xorOperation(int l, int r){
    return func(l-1) ^ func(r);
}
int main(){
    int l; 
    cin>>l; 
    int r; 
    cin>>r; 
    cout<<xorOperation(l, r)<<endl; 
    return 0;
}