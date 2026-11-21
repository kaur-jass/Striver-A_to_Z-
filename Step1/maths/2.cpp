#include<bits/stdc++.h>
using namespace std;
 int reverse(int x) {
        double r;
        while(x!=0)
        {
            int ld = x % 10;
            x = x/10;
            r = r*10 +ld;
        }
        if (r >= INT_MIN && r <= INT_MAX) return r;
        else return 0;
        
    }
int main()
{
   int x;
   cout << "Enter a Number: ";
   cin >> x;
   int reverse_digits = reverse(x);
   cout << "The reverse number is: " << reverse_digits << endl;
   return 0;
}
