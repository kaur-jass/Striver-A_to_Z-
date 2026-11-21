#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{ 
    int a = 65; // ASCII value of 'A'
    for(int i = 0; i < n; i++)
    {
      
        for(int j = 0; j <= i; j++)
        {
            cout << char(a) << " ";
        }
        a++;
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