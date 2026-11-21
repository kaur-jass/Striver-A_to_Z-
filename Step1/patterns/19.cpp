#include<bits/stdc++.h>
using namespace std;
void solve1(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-i+1 ; j++)
        {
            cout << "* ";
        }
        for(int k = 1; k <= 2*(i-1); k++)
        {
            cout << "  ";
        }
        for(int l = 1; l <= n-i+1; l++)
        {
            cout << "* ";
        }
        cout << endl;
    } 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        for(int j = 1; j <= 2*(n-i); j++)
        {
            cout << "  ";
        }
        for(int j = i; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
// void solve2(int n)
// {
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         for(int j = 1; j <= 2*(n-i); j++)
//         {
//             cout << "  ";
//         }
//         for(int j = i; j >= 1; j--)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }
int main()
{
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    solve1(n);
    // solve2(n);
    return 0;
}