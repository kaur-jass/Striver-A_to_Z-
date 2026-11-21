#include<bits/stdc++.h>
using namespace std;
// return 1 if == m 
// return 0 if<m
// return 2 if>m
int func(int mid,int n,int m)
{
    long long ans = 1;
    for(int i = 1; i<=n; i++)
    {
        ans = ans*mid;
        if(ans>m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int square_root(int n,int m)
{
     int s = 1, e = m;
     while(s<=e)
     {
        int mid = s+(e-s)/2;
        int midn = func(mid,n,m);
        if(mid == 1)
        {
            return mid;
        }
        else if(midn == 0) s = mid+1;
        else e = mid-1;
     }
     return -1;
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