#include<bits/stdc++.h>
using namespace std;
void solve1(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(char ch = 'E'-i+1; ch <= 'E'; ch++)
        {
            cout << ch << " ";
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
    return 0;
}