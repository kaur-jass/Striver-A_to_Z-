// Fibonacci Number using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int n; 
    public:
        int fib(int n) {
            if(n <= 1) return n;
            int prev2 = 0, prev = 1;
            // using tabulation
            for(int i = 2; i <= n; i++){ 
                int curr = prev + prev2;
                prev2 = prev;
                prev = curr;
            }
            return prev;       
        }
}; 

int main(){
    int n; 
    cout << "Enter the value of n: ";
    cin >> n;
    Solution obj;
    cout << "The fibonacci of n is : " << obj.fib(n) << endl;
    return 0;
}