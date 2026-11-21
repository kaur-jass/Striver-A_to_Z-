#include<bits/stdc++.h>
using namespace std;

bool setithbit(int n, int i){
    if((n & (1 << i)) != 0) return true;
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