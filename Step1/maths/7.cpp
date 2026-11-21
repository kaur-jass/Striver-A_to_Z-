#include <bits/stdc++.h>
using namespace std;

// int gcd(int x, int y) {
//     int g = 0;
//     int z = max(x, y);
//     int other = min(x, y);
//     vector<int> ls;

//     for (int i = 1; i * i <= z; i++) {
//         if (z % i == 0) {
//             ls.push_back(i);
//             if (z / i != i) {
//                 ls.push_back(z / i);
//             }
//         }
//     }

//     sort(ls.begin(), ls.end());
//     for (auto it : ls) {
//         if (other % it == 0) {
//             g = it;
//         }
//     }

//     return g;
// }
int gcd (int x, int y)
{
    int g = 1;
    for (int i = min(x,y); i>=1; i--)
    {
        if(x % i == 0 && y % i == 0)
        {
            g = i;
            break;
        }
    }
    return g;
}
// Euclidean Algorithm
int gcd2(int x,int y)
{
    while(x>0 && y>0)
    {
        if(x>y)  x = x%y;
        else y = y%x;
    }
    if(x == 0) return y;
    else return x;

}
int main()
{
   int x,y;
   cout << "Enter First number : " ;
   cin >> x;
   cout << "Enter Second number : " ;
   cin >> y;
   cout << "The gcd of x and y is : " << gcd(x,y) << endl;
   cout << "The gcd of x and y is : " << gcd2(x,y) << endl;
   return 0;
}