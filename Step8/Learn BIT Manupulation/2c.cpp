#include<bits/stdc++.h>
using namespace std;
int Convert2Decimal(string x){
    int len = x.length();
    int num = 0; 
    int p2 = 1;
    for(int i = len-1; i>=0; i--){
        if(x[i] == '1'){
            num += p2; 
        }
        p2 = p2*2; 
    }
    return num;
}
int setithbit(int n, int i){
    string res = ""; 
    while(n != 1){
        if(n%2 == 1) res += '1'; 
        else res += '0';
        n = n/2; 
    }
    res += '1';
    if(res[i] == '0') res[i] = '1';
    reverse(res.begin(), res.end());
    return Convert2Decimal(res);
}
int main(){
    int n; 
    cin>>n; 
    int i;
    cin>>i;
    cout<<setithbit(n, i)<<endl; 
    return 0;
}