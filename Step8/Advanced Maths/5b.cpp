#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    // OPTIMAL ANS - USING RECURSION OR BINOMIAL EXPONENTIATION
    double ans = 1.0;
    long long N = n;
    if(N<0) N = -N;
    while(N){
        if(N%2){
            ans = ans * x;
            N = N - 1;
        }
        else{
            x = x * x;
            N = N / 2;
        }
    }
    if(n<0) ans = (double)(1.0)/(double)(ans);
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