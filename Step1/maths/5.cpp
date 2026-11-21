#include<bits/stdc++.h>
using namespace std;
// void divisors(int x)
// {
//      for (int i = 1; i <=x; i++)
//      {
//         if (x % i == 0) {
//             cout << i << endl;
//         }
//      }
// }

void divisors(int x)
{
    // 6 * 6 = 36
    // 7 * 7 <= 36  False
    // O(sqrt(n))
    vector<int> ls;
     for (int i = 1; i*i <= x; i++)
     {
        if (x % i == 0) {
            ls.push_back(i);
            if (x/i != i){
                ls.push_back(x/i);
            }
        }
     }

     // O(n * log n) n is the number of factors
     sort(ls.begin(),ls.end());

     // O(No. of factors)
     for(auto it : ls)
     {
        cout << it << endl;
     }
}
int main()
{
    int x;
    cout << "Enter the Number : ";
    cin >> x;
    cout << "The Divisors of the number are : " << endl ;
    divisors(x);
    return 0;
}