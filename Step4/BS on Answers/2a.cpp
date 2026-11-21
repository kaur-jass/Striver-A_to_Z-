#include<bits/stdc++.h>
using namespace std;

int square_root(int n,int m)
{
     int ans = -1;
     for (int i = 1; i<=m; i++)
     {
        long long mid = pow(i,n); 
        if(mid == m)
        {
            ans = i;
        }
        else if (mid < m)
        {
            continue;
        }
        else break;
     }
     return ans;
}
int main()
{
    int n; 
    cin >> n;
    int m; 
    cin >> m;
    cout << square_root(n,m) << " ";
    return 0;
}