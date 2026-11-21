#include<bits/stdc++.h>
using namespace std;

void SwapBits(int& x, int& y){
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
int main(){
    int x; 
    cin>>x;
    int y; 
    cin>>y;
    cout<< x << " " << y << endl;
    SwapBits(x, y); 
    cout<< x << " " << y << endl;
    return 0;
}