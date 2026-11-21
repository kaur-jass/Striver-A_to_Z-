#include<bits/stdc++.h>
using namespace std;

int square_root(int n,int m)
{
     int s = 1, e = m-1;
     while(s<=e)
     {
        int mid = s+(e-s)/2;
        long long val = pow(mid, n);
        if(val == m)
        {
             return mid;
        }
        else if(val<m)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
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