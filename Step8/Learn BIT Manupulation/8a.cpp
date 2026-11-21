#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if(dividend == divisor) return 1; 
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true;  // +ve
        if(dividend >= 0 && divisor < 0) sign = false; // -ve
        if(dividend < 0 && divisor >= 0) sign = false;
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long quotient = 0; 
        while(n>=d){
            int cnt = 0; 
            while(n >= d<<(cnt+1)){
                cnt++; 
            }
            quotient += 1<<cnt;
            n -= d<<cnt; 
        }
        if(quotient >= (1LL<<31) && sign == true) return INT_MAX;
        if(quotient >= (1LL<<31) && sign == false) return INT_MIN;
        return sign ? quotient : (-1)*quotient;
    }
};

int main(){
    Solution sol; 
    int dividend = 10; 
    int divisor = 3; 
    cout<<sol.divide(dividend, divisor)<<endl; 
    return 0;
}