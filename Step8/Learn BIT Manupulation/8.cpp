#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MAX && divisor == 1) return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long div = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long cnt = 0;
        while (div >= dvs) {
            div -= dvs;
            cnt++;
        }

        cnt *= sign;

        if (cnt > INT_MAX) return INT_MAX;
        if (cnt < INT_MIN) return INT_MIN;
        return (int)cnt;
    }
};

int main(){
    Solution sol; 
    int dividend = 10; 
    int divisor = 3; 
    cout<<sol.divide(dividend, divisor)<<endl; 
    return 0;
}