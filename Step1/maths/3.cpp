#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
    int n;
    n = x;
    double r;
    while(x>0)
    {
        int ld = x%10;
        x = x/10;
        r = r*10 +ld;
    }
    if (n == r) return true;
    else if (n == 0) return true;
    else return false;
}

int main()
{
   int x;
   cout << "Enter a Number: ";
   cin >> x;
   cout << "The given number is " << isPalindrome(x) << " Palindrome";
   return 0;
}