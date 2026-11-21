#include<bits/stdc++.h>
using namespace std;
void solve1(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i ; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void solve2(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n-i ; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void solve3(int n)
{
    for(int i = 1; i <= 2*n-1; i++)
    {
        int stars = i;
        if(i > n)
        {
            stars = 2*n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    solve1(n);
    solve2(n);
    solve3(n);
    return 0;
}