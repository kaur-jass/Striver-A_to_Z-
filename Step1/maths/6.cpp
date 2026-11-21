#include<bits/stdc++.h>
using namespace std;

// bool prime(int x)
// {
//     if (x <= 1) return false;
//     if(x == 2 || x == 3) return true;
//     if (x % 2 == 0 || x % 3 == 0) return false;
//     else {
//     for(int i = 5; i*i <= x; i += 6)
//     {
//         if (x%i == 0 || x % (i+2) == 0)
//         {
//             return false;
//         }
//     }
//     return true;
//     }
// }

bool prime(int x)
{
    int cnt = 0;
    for(int i = 1; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            cnt++;
            if((x%i) != i) cnt++;
        }
    }
    if (cnt == 2) return true;
    else return false;
    
}

int main ()
{
   int x;
   cout << "Enter a number : " ;
   cin >> x;
   cout << "The given Numebr is prime (1 for true / 0 for False) : " << prime(x);
   return 0;
}

