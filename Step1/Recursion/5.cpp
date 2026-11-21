#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    if (n == 0) return;
    cout << n << endl;
    n--;
    print(n);
}
int main()
{
   int n;
   cout << "Enter a Number : ";
   cin >> n;
   print(n);
   return 0;
}