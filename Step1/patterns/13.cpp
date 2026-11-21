#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{ 
    int a = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    solve(n);
    return 0;
}