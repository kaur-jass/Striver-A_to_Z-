#include<bits/stdc++.h>
using namespace std;

int countdigits(int n)
{
    int count;
    count = 0;
    while(n>0)
    {
        int ld;
        ld = n%10;
        n = n/10;
        count++;
    }
    return count;
}


// Another way to extract number of digits
int cntdigits(int n)
{
   int cnt;
   cnt = (int)(log10(n)+1);
   return cnt;
}

int main()
{
   int n;
   cout << "Enter a Number: ";
   cin >> n;
   int cnt = countdigits(n);
   int c = cntdigits(n);
   cout << "Number of digits in the number is: " << cnt << endl;
   cout << "Number of digits in the number is: " << c << endl;
   return 0;
}