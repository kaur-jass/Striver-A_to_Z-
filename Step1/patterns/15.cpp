#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{ 
    
    for(int i = 1; i <= n; i++)
    {
        int a = 65; // ASCII value of 'A'
        for(int j = 1 ; j <= n-i+1; j++)
        {
            cout << char(a) << " ";
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