#include<bits/stdc++.h>
using namespace std;
void solve1(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2*i-1; k++)
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
        for(int j = 1; j <= i-1; j++)
        {
            cout << "  ";
        }
        for(int k = 1; k <= 2*(n-i)+1; k++)
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
    return 0;
}