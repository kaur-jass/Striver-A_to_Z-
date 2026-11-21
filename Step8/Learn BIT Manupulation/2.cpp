#include<bits/stdc++.h>
using namespace std;

bool setithbit(int n, int i){
    string res = ""; 
    while(n != 1){
        if(n%2 == 1) res += '1'; 
        else res += '0';
        n = n/2; 
    }
    res += '1';
    if(res[i] == '1') return true; 
    return false;
}
int main(){
    int n; 
    cin>>n; 
    int i;
    cin>>i;
    cout<<setithbit(n, i)<<endl; 
    return 0;
}