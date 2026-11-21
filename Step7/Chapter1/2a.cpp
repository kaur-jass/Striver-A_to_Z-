#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    // OPTIMAL ANS - USING RECURSION OR BINOMIAL EXPONENTIATION
    if(n == 0) return 1; 
    double half; 
    double result;
    long long N; 
    if(n<0){                         //*
        x = 1/x; 
        N = -(long long)n;        //* This is very important causes runtime again and again 
    } 
    if(n>=0) N=n; 
    if(N%2 == 0){
        half = myPow(x, N/2); 
        result = half*half;       // this half*half concept important 
    }
    else{
        half = myPow(x, (N-1)/2); 
        result = x*half*half;
    }
    return result;
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