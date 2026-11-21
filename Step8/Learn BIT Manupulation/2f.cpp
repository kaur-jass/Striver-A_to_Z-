#include<bits/stdc++.h>
using namespace std;

int setithbit(int n, int i){
    return (n ^ (1 << i));
}
int main(){
    int n; 
    cin>>n; 
    int i;
    cin>>i;
    cout<<setithbit(n, i)<<endl; 
    return 0;
}