#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    // BRUTE FORCE 
    double ans = 1; 
    if(n == 0) return ans; 
    if(n>0){
        for(int i = 0; i<n ;i++) ans = ans*x;
    }
    else if(n<0){
        x = 1/x; 

        for(int i = 0; i<(-1)*n ;i++) ans = ans*x;
    }
    return ans;
}

int main()
{
    double x; 
    int n; 
    cout<<"Enter the value of x and n : ";
    cin>>x>>n; 
    double result = myPow(x,n); 
    cout<<"The value of x raised to n is : "<<result<<endl;
    return 0;
}