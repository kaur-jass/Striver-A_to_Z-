#include<bits/stdc++.h>
using namespace std;
// void solve (int n)
// {
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= n; j++)
//         {
//             if (j == 1 || j == n || i == 1 || i == n)
//             {
//                 cout << "4 ";
//             }
//             else if (i == 2 || i == n-1 || j ==2 || j == n-1)
//             {
//                 cout << "3 ";
//             }
//             else if (i == 3 || i == n-2 || j == 3 || j == n-2)
//             {
//                 cout << "2 ";
//             }
//             else
//             {
//                 cout << "1 ";
//             }
//         }
//         cout << endl;
//     }
// }
void solve(int n)
{
    for(int i = 0;i < 2*n - 1; i++)
    {
        for(int j = 0; j < 2*n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2*n - 2) - j;
            int bottom = (2*n - 2) - i;
            cout << (n - min(min(top, left), min(right, bottom))) << " ";
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