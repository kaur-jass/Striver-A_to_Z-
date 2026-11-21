#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int myPow(int x, long long n)
{
    if(n == 0) return 1; 
    long long half; 
    long long result;
    if(n%2 == 0){
        half = myPow(x, n/2); 
        result = (half*half)%MOD;
    }
    else{
        half = myPow(x, (n-1)/2); 
        result = (1LL * x * half * half) % MOD;
    } 
    return result;
}
int countGoodNumbers(long long n) {
    long long  answer = 1;
    long long oddans = 1; 
    long long evenans = 1; 
    long long oddnos = n/2; 
    long long evennos = 0; 
    if(n%2 == 0) evennos = n/2; 
    else evennos = n/2+1; 
    oddans = myPow(4,oddnos); 
    evenans = myPow(5, evennos);
    answer = (oddans*evenans)%MOD; 
    return answer;
}
int main()
{
    long long n; 
    cout<<"Enter the value of n : ";
    cin>>n; 
    int result = countGoodNumbers(n); 
    cout<<"The count of good numbers is : "<<result<<endl;
    return 0;
}